#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class usuario {
private:
    string nombre;
    vector<int> numeros;
    vector<int> permisos;

public:
    // Constructor
    usuario(string nombreInput, vector<int> numerosInput, vector<int> permisosInput) {
        nombre = nombreInput;
        numeros = numerosInput;
        permisos = permisosInput;
    }

    bool verificarPermiso(int permiso) {
        for (int p : permisos) {
            if (p == permiso) {
                return true;
            }
        }
        return false;
    }

    void salir() {
        cout << "A salido del programa" << endl;
    }

    int sumaVector() {
        int suma = 0;
        for (int val1 : numeros) {
            suma += val1;
        }
        return suma;
    }

    float promedioVector() {
        float suma = sumaVector();
        return suma / numeros.size();
    }

    int modaVector() {
        unordered_map<int, int> frecuencia;
        for (int num : numeros) {
            frecuencia[num]++;
        }
        int moda = numeros[0];
        int maxFrecuencia = 0;
        for (const auto& pair : frecuencia) {
            if (pair.second > maxFrecuencia) {
                moda = pair.first;
                maxFrecuencia = pair.second;
            }
        }
        return moda;
    }

    int contarVector() {
        return numeros.size();
    }

    void crearArchivo(string path) {
        ofstream file(path);
        file.open(path);
        file.close();
    }

    void escribirArchivo(string path, string texto) {
        ofstream file(path, std::ios::app);
        if (file.is_open()) {
            file << texto << endl;
            file.close();
            cout << "Contenido agregado al archivo." << endl;
        }
        else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
};