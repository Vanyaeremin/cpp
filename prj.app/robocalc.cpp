#include "robocalc.hpp"
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
        RoboCalc* cmd = nullptr;

        if (command == "OUT") {
            cmd = new OUT(rc, number);
            cmd->execute();
            std::vector<RoboCalc*> commands = rc.get_commands();
            for (RoboCalc* com : commands) {
                com->execute();
            }
            output << rc.get_number() << std::endl;
            delete cmd;
            cmd = nullptr;
        }

        else if (command == "REV") {
            cmd = new REV(rc, number);
            cmd->execute();
            delete cmd;
            cmd = nullptr;
        } 

        else {
            try {
                if (command == "MUL") {
                    cmd = new MUL(rc, number);
                }
                else if (command == "DIV") {
                    cmd = new DIV(rc, number);
                }
                else if (command == "ADD") {
                    cmd = new ADD(rc, number);
                }
                else if (command == "SUB") {
                    cmd = new SUB(rc, number);
                }
                else {
                    throw std::invalid_argument("ERR: Wrong command");
                }
                std::vector<RoboCalc*> com = rc.get_commands();
                com.push_back(cmd);
                rc.set_commands(com);
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

std::vector<RoboCalc*> RoboCalc::get_commands() const noexcept {
    return commands_;
}

void RoboCalc::set_commands(std::vector<RoboCalc*> result) noexcept {
    commands_ = result;
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
    std::vector<RoboCalc*> vec = calc_.get_commands();
    try {
        if (number_ <= vec.size() && number_ >= 0) {
            vec.erase(vec.end() - number_, vec.end());
            calc_.set_commands(vec);
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

