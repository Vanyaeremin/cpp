#include <prj.app/robocalc.hpp>

int main(int argc, char* argv[]) {
    try {
        std::string inputFile;
        std::string outputFile;
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            if (arg == "-i") {
                if (i + 1 < argc) {
                    inputFile = argv[i + 1];
                    i++;
                }
                else {
                    throw std::invalid_argument("ERR: The input file name for the parameter is missing -i");
                }
            }
            else if (arg == "-o") {
                if (i + 1 < argc) {
                    outputFile = argv[i + 1];
                    i++;
                }
                else {
                    throw std::invalid_argument("ERR: The output file name for the parameter is missing -o");
                }
            }
            else {
                throw std::invalid_argument("ERR: Unknown parameter");
            }
        }
        StartProgram(inputFile, outputFile);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        exit(1);
    }
}