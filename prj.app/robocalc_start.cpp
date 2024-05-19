#include <prj.app/robocalc.hpp>

int main(int argc, char* argv[]) {
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
                std::cout << "ERR: Отсутствует имя файла ввода для параметра -i" << std::endl;
                return 1;
            }
        }

        else if (arg == "-o") {
            if (i + 1 < argc) {
                outputFile = argv[i + 1];
                i++;
            }
            else {
                std::cout << "ERR: Отсутствует имя файла вывода для параметра -o" << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "ERR: Неизвестный параметр: " << arg << std::endl;
            return 1;
        }
    }
    StartProgram(inputFile, outputFile);
    return 0;
}