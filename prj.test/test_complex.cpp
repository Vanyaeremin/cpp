#include <complex/complex.hpp>

bool testParse(const std::string& str)
{
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good())
    {
        std::cout << "Read success: " << str << " -> " << z << std::endl;
    }
    else
    {
        std::cout << "Read error : " << str << " -> " << z << std::endl;
    }
    return istrm.good();
}

void test(const Complex& c1, const Complex& c2, const double c) {
    std::cout << "--READING TEST--" << std::endl;
    std::cout << "Test1: " << testParse("{8.9,9}") << std::endl;
    std::cout << "Test2: " << testParse("{8.9, 9}") << std::endl;
    std::cout << "Test3: " << testParse("{8.9,9") << std::endl;
    Complex c11 = c1;
    Complex c32;
    c32 = c;
    Complex c0 = { 0,0 };
    std::cout << "\n----OPERATION TEST----\nComplex c1 = " << c1 << "; Complex c2 = " << c2 << "; double c = " << c << "\n----------------------\n" << std::endl;

    std::cout << " \n--Assignment--\n\n " << std::endl;
    std::cout << "Test1: " << "c3 = c1\nc3 = " << c11 << "; Correct answer : {2,3}\nStatus: OK\n\n";
    std::cout << "Test2: " << "c3 = c\nc3 = " << c32 << "; Correct answer: {6,0}\nStatus: OK\n\n";

    std::cout << " \n--Addition operation--\n\n " << std::endl;
    std::cout << "Test1: " << c1 << " + " << c2 << "\nanswer: " << (c1 + c2) << "\nCorrect answer: {6,8}\nStatus: OK\n\n";
    std::cout << "Test2: " << c1 << " + " << c << "\nanswer: " << (c1 + c) << "\nCorrect answer: {8,3}\nStatus: OK\n\n";
    std::cout << "Test3: " << c << " + " << c1 << "\nanswer: " << (c + c1) << "\nCorrect answer: {8,3}\nStatus: OK\n\n";
    std::cout << "Test4: " << c1 << " += " << c2 << "\nc1 = " << (c11 += c2) << "\nCorrect answer: {6,8}\nStatus: OK\n\n";
    c11 = c1;
    std::cout << "Test5: " << c1 << " += " << c << "\nc1 = " << (c11 += c) << "\nCorrect answer: {8,3}\nStatus: OK\n\n";
    c11 = c1;

    std::cout << " \n--Subtraction operation--\n\n " << std::endl;
    std::cout << "Test1: " << c1 << " - " << c2 << "\nanswer: " << (c1 - c2) << "\nCorrect answer: {-2,-2} \nStatus: OK\n\n";
    std::cout << "Test2: " << c1 << " - " << c << "\nanswer: " << (c1 - c) << "\nCorrect answer: {-4,3}\nStatus: OK\n\n";
    std::cout << "Test3: " << c << " - " << c1 << "\nanswer: " << (c - c1) << "\nCorrect answer: {4,-3}\nStatus: OK\n\n";
    std::cout << "Test4: " << c1 << " -= " << c2 << "\nc1 = " << (c11 -= c2) << "\nCorrect answer: {-2,-2}\nStatus: OK\n\n";
    c11 = c1;
    std::cout << "Test5: " << c1 << " -= " << c << "\nc1 = " << (c11 -= c) << "\nCorrect answer: {-4,3}\nStatus: OK\n\n";
    c11 = c1;

    std::cout << " \n--Multiplication operation--\n\n " << std::endl;
    std::cout << "Test1: " << c1 << " * " << c2 << "\nanswer: " << (c1 * c2) << "\nCorrect answer: {-7,22}\nStatus: OK\n\n";
    std::cout << "Test2: " << c1 << " * " << c << "\nanswer: " << (c1 * c) << "\nCorrect answer: {12,18}\nStatus: OK\n\n";
    std::cout << "Test3: " << c << " * " << c1 << "\nanswer: " << (c * c1) << "\nCorrect answer : {12, 18}\nStatus: OK\n\n";
    std::cout << "Test4: " << c1 << " *= " << c2 << "\nc1 = " << (c11 *= c2) << "\nCorrect answer: {-7,22}\nStatus: OK\n\n";
    c11 = c1;
    std::cout << "Test5: " << c1 << " *= " << c << "\nc1 = " << (c11 *= c) << "\nCorrect answer: {12,18}\nStatus: OK\n\n";
    c11 = c1;

    std::cout << " \n--Division operation--\n\n " << std::endl;
    std::cout << "Test1: " << c1 << " / " << c2 << "\nanswer: " << (c1 / c2) << "\nCorrect answer: {0.560976, 0.0487805}\nStatus: OK\n\n";
    std::cout << "Test2: " << c1 << " / " << c << "\nanswer: " << (c1 / c) << "\nCorrect answer: {0.333333,0.5}\nStatus: OK\n\n";
    std::cout << "Test2: " << c << " / " << c1 << "\nanswer: " << (c / c1) << "\nCorrect answer: {0.923077,-1.38462}\nStatus: OK\n\n";
    std::cout << "Test4: " << c1 << " /= " << c2 << "\nc1 = " << (c11 /= c2) << "\nCorrect answer: {0.560976, 0.0487805}\nStatus: OK\n\n";
    c11 = c1;
    std::cout << "Test5: " << c1 << " /= " << c << "\nc1 = " << (c11 /= c) << "\nCorrect answer: {0.333333,0.5}\nStatus: OK\n\n";
    c11 = c1;

    std::cout << " \n--Modulo value--\n\n " << std::endl;
    std::cout << "Test1: " << "abs(" << c1 << ")\nanswer: " << abs(c1) << "\nCorrect answer: 3.60555\nStatus: OK\n\n";
    std::cout << "Test2: " << "abs(" << c2 << ")\nanswer: " << abs(c2) << "\nCorrect answer: 6.40312\nStatus: OK\n\n";

    std::cout << " \n--Conjugate for a number--\n\n " << std::endl;
    std::cout << "Test1: " << "Conjugate for (" << c1 << ")\nanswer: " << !(c1) << "\nCorrect answer: {2,-3}\nStatus: OK\n\n";
    std::cout << "Test2: " << "Conjugate for (" << c2 << ")\nanswer: " << !(c2) << "\nCorrect answer: {4,-5}\nStatus: OK\n\n";

    std::cout << " \n--Equality--\n\n " << std::endl;
    std::cout << "Test1: " << c1 << " == " << c2 << "\nanswer: " << (c1 == c2) << "\nCorrect answer: 0\nStatus: OK\n\n";
    std::cout << "Test2: " << c1 << " != " << c2 << "\nanswer: " << (c1 != c2) << "\nCorrect answer: 1\nStatus: OK\n\n";
    std::cout << "Test3: " << c1 << " == " << c << "\nanswer: " << (c1 == c) << "\nCorrect answer: 0\nStatus: OK\n\n";
    std::cout << "Test4: " << c1 << " != " << c << "\nanswer: " << (c1 != c) << "\nCorrect answer: 1\nStatus: OK\n\n";

    std::cout << " \n--Exponentiation (integer)--\n\n " << std::endl;
    std::cout << "Test1: pow(" << c11 << ", 5)\nanswer: " << pow(c11, 5) << "\nCorrect answer: {122,-597}\nStatus: OK\n\n";
    std::cout << "Test2: pow(" << c11 << ", 0)\nanswer: " << pow(c11, 0) << "\nCorrect answer: {1,0}\nStatus: OK\n\n";
    std::cout << "Test3: pow(" << c11 << ", -2)\nanswer: " << pow(c11, -2) << "\nCorrect answer: {-0.0295858,-0.0710059}\nStatus: OK\n\n";
    std::cout << "Test4: pow(" << c0 << ", 5)\nanswer: " << pow(c0, 5) << "\nCorrect answer: {0,0}\nStatus: OK\n\n";

    Complex um = -c1;
    std::cout << " \n--Unary minus--\n\n " << std::endl;
    std::cout << "Test1: -" << c1 << "\nanswer: " << um << "\nCorrect answer : {-2,-3}\nStatus : OK\n\n";

    std::cout << " \n--Checking division by zero--\n\n " << std::endl;
    std::cout << "Test: " << c11 << " / {0,0};\nResult: " << (c11 / c0);
}

int main() {
    Complex c1 = { 2,3 };
    Complex c2 = { 4,5 };
    double c = 6;
    test(c1, c2, c);
}
