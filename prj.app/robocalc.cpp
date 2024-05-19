#include "robocalc.hpp"
#include <filesystem>

void StartProgram(std::string inputfile, std::string outputfile) {

    RoboCalc rc;
    std::ifstream file(inputfile);
    std::ofstream output(outputfile);

    if (!file.is_open()) {
        std::cout << "ERR: Can not open file!";
        exit(1);
    }
    std::string line;

    while (std::getline(file, line)) {
        int number = std::stoi(line.substr(4));
        if (line.substr(0, 3) == "OUT") {
            OUT out(rc, number);
            out.out();
            for (std::string str : rc.get_commands()) {
                int num = std::stoi(str.substr(4));
                if (str.substr(0, 3) == "MUL") {
                    MUL mul(rc, num);
                    mul.multiply();
                }
                else if (str.substr(0, 3) == "DIV") {
                    DIV div(rc, num);
                    div.division();
                }
                else if (str.substr(0, 3) == "ADD") {
                    ADD add(rc, num);
                    add.addition();
                }
                else if (str.substr(0, 3) == "SUB") {
                    SUB sub(rc, num);
                    sub.subtraction();
                }
            }
            output << rc.get_number() << std::endl;
        }
        else {
            if (line.substr(0, 3) == "REV") {
                REV rev(rc, number);
                rev.rev();
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

void OUT::out() {
    calc.set_number(number_);
}

int RoboCalc::get_number() {
    return number;
 }

void RoboCalc::set_number(int result) {
    number = result;
}

std::vector<std::string> RoboCalc::get_commands() {
    return commands;
}

void RoboCalc::set_commands(std::vector<std::string> result) {
    commands = result;
}

void MUL::multiply() {
    int result = calc.get_number() * multiplier;
    calc.set_number(result);
}

void DIV::division() {
    if (divider_ == 0) {
        std::cout << "ERR: Division by zero";
        exit(1);
    }
    else {
        int result = calc.get_number() / divider_;
        calc.set_number(result);
    }
}

void SUB::subtraction() {
    int result = calc.get_number() - deductible_;
    calc.set_number(result);
}

void ADD::addition() {
    int result = calc.get_number() + summand_;
    calc.set_number(result);
}

void REV::rev() {
    std::vector<std::string> vec = calc.get_commands();
    if (number_ <= vec.size() && number_ >= 0) {
        vec.erase(vec.end() - number_, vec.end());
        calc.set_commands(vec);
    }
    else {
        std::cout << "ERR: Invalid argument to REV command";
        exit(1);
    }

}

