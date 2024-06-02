#include "robocalc.hpp"

std::vector<std::unique_ptr<RoboCalc>> commands;

void StartProgram(std::string inputfile, std::string outputfile) {

    RoboCalc rc;
    std::ifstream file(inputfile);
    std::ofstream output(outputfile);
    try {
        if (!file.is_open()) {
            throw std::invalid_argument("ERR: Can not open file!\n");
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    std::string line;

    while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::string command;
        double number;
        iss >> command >> number;
        std::unique_ptr<RoboCalc> cmd = nullptr;

        if (command == "OUT") {
            cmd = std::make_unique<OUT>(rc, number);
            cmd->execute();
            for (const auto& com : commands) {
                com->execute();
            }
            output << rc.get_number() << std::endl;
        }

        else if (command == "REV") {
            cmd = std::make_unique<REV>(rc, number);
            cmd->execute();
        } 

        else {
            try {
                if (command == "MUL") {
                    commands.push_back(std::make_unique <MUL>(rc, number));
                }
                else if (command == "DIV") {
                    commands.push_back(std::make_unique <DIV>(rc, number));
                }
                else if (command == "ADD") {
                    commands.push_back(std::make_unique <ADD>(rc, number));
                }
                else if (command == "SUB") {
                    commands.push_back(std::make_unique <SUB>(rc, number));
                }
                else {
                    throw std::invalid_argument("ERR: Wrong command");
                }
            }
            catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                exit(1);
            }
        }
    }    
    file.close();
    output.close();
}

void OUT::execute() {
    calc_.set_number(number_);
}

int RoboCalc::get_number() const noexcept {
    return number_;
 }

void RoboCalc::set_number(int result) noexcept {
    number_ = result;
}

void MUL::execute() {
    int result = calc_.get_number() * multiplier_;
    calc_.set_number(result);
}

void DIV::execute() {
    try {
        if (divider_ == 0) {
            throw std::invalid_argument("ERR: Division by zero");
        }
        else {
            int result = calc_.get_number() / divider_;
            calc_.set_number(result);
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

void SUB::execute() {
    int result = calc_.get_number() - deductible_;
    calc_.set_number(result);
}

void ADD::execute() {
    int result = calc_.get_number() + summand_;
    calc_.set_number(result);
}

void REV::execute() {
    try {
        if (number_ <= commands.size() && number_ >= 0) {
            commands.erase(commands.end() - number_, commands.end());
        }
        else {
            throw std::invalid_argument("ERR: Invalid argument to REV command");
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }

}

