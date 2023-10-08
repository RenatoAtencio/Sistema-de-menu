#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> invertedIndex;

    if (argc < 3) {
        std::cerr << "No dio suficientes argumentos";
        return 1;  // Termina el programa con un código de error
    }

    std::string nombreCarpetaOut = argv[1];
    std::string pathOutput = "../Trabajo4/" + nombreCarpetaOut;
    for (const auto& entry : fs::directory_iterator(pathOutput)) {
        if (entry.is_regular_file()) {
            // Verifica si el nombre del archivo comienza con "file"
            std::string filename = entry.path().filename();
            if (filename.rfind("file",0) == 0) {
                std::ifstream inputFile(entry.path());
                std::string line;

                while (std::getline(inputFile, line)) {
                    std::istringstream iss(line);
                    std::string word;
                    int count;

                    if (std::getline(iss, word, ',') && iss >> count) {
                        // Agrega la palabra y su información al índice invertido
                        invertedIndex[word].emplace_back(filename, count);
                    }
                }
            }
        }
    }

    // Escribe el índice invertido en el archivo "indiceInvertido.idx"
    std::string nombreIndexFile = argv[2];
    std::string pathIndex = "../Trabajo4/" + nombreIndexFile;
    std::ofstream outputFile(pathIndex);
    for (const auto& entry : invertedIndex) {
        outputFile << entry.first << ":";
        for (const auto& info : entry.second) {
            outputFile << "(" << info.first << "," << info.second << ");";
        }
        outputFile << "\n";
    }

    std::cout << "El proceso pid = " << getpid() << " genero el archivo: " << nombreIndexFile << std::endl;


    return 0;
}
