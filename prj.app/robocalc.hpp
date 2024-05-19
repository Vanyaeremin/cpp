#pragma once
#ifndef ROBOCALC_HPP
#define ROBOCALC_HPP

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class RoboCalc {
public:
    RoboCalc() = default;
    explicit RoboCalc(std::vector<std::string> commands): commands(commands) {}
    ~RoboCalc() = default;
    int get_number();
    void set_number(int commands);
    std::vector<std::string> get_commands();
    void set_commands(std::vector<std::string> commands);

private:
    int number;
    std::vector<std::string> commands;
};

class MUL : public RoboCalc {
public:
    MUL() = default;
    MUL(RoboCalc& calc, int multiplier): calc(calc), multiplier(multiplier) {}
    ~MUL() = default;
    void multiply();

private:
    RoboCalc& calc;
    int multiplier;
};

class DIV : public RoboCalc {
public:
    DIV() = default;
    DIV(RoboCalc& calc, int divider) : calc(calc), divider_(divider) {}
    ~DIV() = default;
    void division();

private:
    RoboCalc& calc;
    int divider_;
};

class SUB : public RoboCalc {
public:
    SUB() = default;
    SUB(RoboCalc& calc, int deductible) : calc(calc), deductible_(deductible) {}
    ~SUB() = default;
    void subtraction();

private:
    RoboCalc& calc;
    int deductible_;
};

class ADD : public RoboCalc {
public:
    ADD() = default;
    ADD(RoboCalc& calc, int summand) : calc(calc), summand_(summand) {}
    ~ADD() = default;
    void addition();

private:
    RoboCalc& calc;
    int summand_;
};

class OUT : public RoboCalc {
public:
    OUT() = default;
    OUT(RoboCalc& calc, int number) : calc(calc), number_(number) {}
    ~OUT() = default;
    void out();

private:
    RoboCalc& calc;
    int number_;
};

class REV : public RoboCalc {
public:
    REV() = default;
    REV(RoboCalc& calc, int number) : calc(calc), number_(number) {}
    ~REV() = default;
    void rev();

private:
    RoboCalc& calc;
    int number_;
};

void StartProgram(std::string inputfile, std::string outputfile);

#endif 
