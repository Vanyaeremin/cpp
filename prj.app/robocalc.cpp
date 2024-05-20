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
        std::cout << e.what();
        exit(1);
    }
    std::string line;

    while (std::getline(file, line)) {
        int number = std::stoi(line.substr(4));
        if (line.substr(0, 3) == "OUT") {
            OUT out(rc, number);
            out.execute();
            for (std::string str : rc.get_commands()) {
                int num = std::stoi(str.substr(4));
                if (str.substr(0, 3) == "MUL") {
                    MUL mul(rc, num);
                    mul.execute();
                }
                else if (str.substr(0, 3) == "DIV") {
                    DIV div(rc, num);
                    div.execute();
                }
                else if (str.substr(0, 3) == "ADD") {
                    ADD add(rc, num);
                    add.execute();
                }
                else if (str.substr(0, 3) == "SUB") {
                    SUB sub(rc, num);
                    sub.execute();
                }
            }
            output << rc.get_number() << std::endl;
        }
        else {
            if (line.substr(0, 3) == "REV") {
                REV rev(rc, number);
                rev.execute();
            }
            else {
                std::vector<std::string> com = rc.get_commands();
                com.push_back(line);
                rc.set_commands(com);
            }
        }
    }
    file.close();
    output.close();
}

void OUT::execute() noexcept {
    calc_.set_number(number_);
}

int RoboCalc::get_number() const noexcept {
    return number_;
 }

void RoboCalc::set_number(int result) noexcept {
    number_ = result;
}

std::vector<std::string> RoboCalc::get_commands() const noexcept {
    return commands_;
}

void RoboCalc::set_commands(std::vector<std::string> result) noexcept {
    commands_ = result;
}

void MUL::execute() noexcept {
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
        std::cout << e.what();
        exit(1);
    }
}

void SUB::execute() noexcept {
    int result = calc_.get_number() - deductible_;
    calc_.set_number(result);
}

void ADD::execute() noexcept {
    int result = calc_.get_number() + summand_;
    calc_.set_number(result);
}

void REV::execute() {
    std::vector<std::string> vec = calc_.get_commands();
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
        std::cout << e.what();
        exit(1);
    }

}

