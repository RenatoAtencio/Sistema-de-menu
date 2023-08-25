#include "funciones.h"

using namespace std;

vector<int> stringSepararPorComa(string secuencia) {
    vector<int> vectorInt;
    stringstream stream(secuencia);
    string numero;
    while (getline(stream, numero, ',')) {
        int num = stoi(numero);
        vectorInt.push_back(num);
    }
    return vectorInt;
}

vector<int> vectorstoi(vector<string> vectorString) {
    vector<int> vectorInt;
    for (int j = 1; j < vectorString.size();j++) {
        int num = stoi(vectorString[j]);
        vectorInt.push_back(num);
    }
    return vectorInt;
}