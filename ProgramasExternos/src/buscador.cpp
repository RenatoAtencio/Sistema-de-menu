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

using namespace std;

vector<pair<string, int>> separarVectorResults(string vectorResults);
unordered_map<string, vector<pair<string, int>>>  makeUnorderedMap(string pathFile);


int main(int argc, char* argv[]) {
    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    unordered_map<string, vector<pair<string, int>>> allSearchResults;
    unordered_map<string, vector<pair<string, int>>> goodSearchResults;
    if (argc < 3) {
        cerr << "No ingreso suficientes argumentos" << endl;
        return 0;
    }

    // Paso el .idx a invertedIndex
    string nombreIndice = argv[1];
    invertedIndex = makeUnorderedMap("../Trabajo5/" + nombreIndice);

    // Creo la estructura de la busqueda
    string searchInput = argv[2];
    istringstream inputStream(searchInput);
    string word;
    int searchInputSize = 0;

    while (getline(inputStream, word, ' ')) {
        searchInputSize++;
        if (invertedIndex.find(word) != invertedIndex.end()) {
            // Acceder al vector de pares asociado a la clave y recorrerlo
            for (const pair<string, int>& entry : invertedIndex[word]) {
                allSearchResults[entry.first].emplace_back(word, entry.second);
            }
        }
        else {
            cout << "No se encontro concidencias de la palabra: " << word << endl;
        }
    }

    // Paso todos los resultados que contengan la misma cant de palabras
    // Por ahora muestra solo los que tengan todas las palabras
    for (const auto& entry : allSearchResults) {
        int vectorSize = entry.second.size();
        if (vectorSize == searchInputSize) {
            goodSearchResults[entry.first] = entry.second;
        }
    }

    // Sumar las cantidades
    vector<pair<string,int>> endResults;
    for (const auto& entry : goodSearchResults) {
        int sum = 0;
        const vector<pair<string, int>>& pairs = entry.second;
        for (const pair<string, int>& keyValue : pairs) {
            int value = keyValue.second;
            sum = sum + value;
        }
        endResults.emplace_back(entry.first,sum);
    }

    // print vector
    for (const pair<string, int>& result : endResults) {
        string fileName = result.first;
        int value = result.second;
        cout << "Archivo: " << fileName << ", Valor: " << value << endl;
    }

    // Print unordered map
    // for (const auto& entry : goodSearchResults) {
    //     cout << entry.first << ":";
    //     for (const auto& pair : entry.second) {
    //         cout << "(" << pair.first << "," << pair.second << ");";
    //     }
    //     cout << endl;
    // }

    return 1;
}

unordered_map<string, vector<pair<string, int>>> makeUnorderedMap(string pathFile) {
    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    ifstream inputFile(pathFile);
    string line;
    // line seria una linea del archivo .idx
    while (getline(inputFile, line)) {
        istringstream lineStream(line);
        string word, vectorResults;
        // Separo la linea en : y le doy los valores de word = palabra y vectorResults = vector
        while ((getline(lineStream, word, ':')) && (getline(lineStream, vectorResults, ':'))) {
            invertedIndex[word] = separarVectorResults(vectorResults);
        }
    }

    // for (const auto& entry : invertedIndex) {
    //     cout << entry.first << ":";
    //     for (const auto& pair : entry.second) {
    //         cout << "(" << pair.first << "," << pair.second << ");";
    //     }
    //     cout << endl;
    // }

    inputFile.close();
    return invertedIndex;
}

vector<pair<string, int>> separarVectorResults(string vectorResults) {
    vector<pair<string, int>> outputVector;
    // Le quito el ultimo ; que quedaba sobrando
    vectorResults = vectorResults.substr(0, vectorResults.size() - 1);
    istringstream lineStreamVector(vectorResults);
    string vector;
    while (getline(lineStreamVector, vector, ';')) {
        // Le quito los ( )
        vector = vector.substr(1, vector.size() - 2);
        istringstream lineStreamResult(vector);
        string file, amount;
        while ((getline(lineStreamResult, file, ',')) && (getline(lineStreamResult, amount, ','))) {
            outputVector.emplace_back(file, stoi(amount));
        }
    }
    return outputVector;

}