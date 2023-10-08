#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> invertedIndex;

    // Recorre los archivos en la carpeta "out"
    for (const auto& entry : fs::directory_iterator("../Trabajo4/data/Files/OutputFiles")) {
        if (entry.is_regular_file()) {
            std::ifstream inputFile(entry.path());
            std::string line;
            
            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                std::string word;
                int count;

                if (std::getline(iss, word, ',') && iss >> count) {
                    // Agrega la palabra y su información al índice invertido
                    invertedIndex[word].emplace_back(entry.path().filename(), count);
                }
            }
        }
    }

    // Escribe el índice invertido en el archivo "indiceInvertido.idx"
    std::ofstream outputFile("../Trabajo4/data/Files/OutputFiles/indiceInvertido.idx");
    for (const auto& entry : invertedIndex) {
        outputFile << entry.first << ":";
        for (const auto& info : entry.second) {
            outputFile << "(" << info.first << "," << info.second << ");";
        }
        outputFile << "\n";
    }

    std::cout << "Índice invertido generado con éxito en 'indiceInvertido.idx'" << std::endl;

    return 0;
}
