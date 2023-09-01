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

int sumaVector(vector<int> v1);
float promedioVector(vector<int> v1);
int modaVector(vector<int> v1);
int contarVector(vector<int> v1);
void crearArchivo(string path);
bool verificarArchivo(string path);
void escribirArchivo(string path, string texto);
vector<vector<string>> cargarTexto(string nombreTxt);

int main(int argc, char* argv[])
{
    // creo un vector con toda la informacion
    vector<vector<string>> usuarios;
    usuarios = cargarTexto("users.txt");

    // tomo la entrada al ejecutar el codigo, -u es para el user y -v es para el vector de numeros
    char c;
    string texto, path, respuesta, vectorUserStr, nombreUser;
    vector<int> vectorUserInt;

    while ((c = getopt(argc, argv, "u:v:f:t:")) != -1) {
        switch (c) {
        case 'u': {
            nombreUser = optarg;
            // cout << nombreUser << endl;
            break;
        }
        case 'v': {
            vectorUserStr = optarg;
            stringstream stream(vectorUserStr);
            string numero;

            while (getline(stream, numero, ',')) {
                int num = stoi(numero);
                vectorUserInt.push_back(num);
            }
            // cout << vectorUserStr << endl;
            break;
        }
        case 'f': {
            path = optarg;
            break;
        }
        case 't': {
            texto = optarg;
            break;
        }
        }
    }

    // verifico si el user esta en la base de datos, por ahora es case sensitive
    int i = 0;
    while (i < usuarios.size() && nombreUser != usuarios[i][0]) {
        i++;
    }

    // si el user no esta en la bd lo indica
    if (i == usuarios.size()) {
        cout << "User no esta registrado" << endl;
    }
    // si esta en la base de datos entonces muestra los resultados dependiendo de los permisos
    else {
        // Creo el vector de los permisos pero en int
        vector<int> permisosInt;
        for (int j = 1; j < usuarios[i].size();j++) {
            int num = stoi(usuarios[i][j]);
            permisosInt.push_back(num);
        }
        // imprime toda la selecion y se encarga de diferenciar si los user tienen permisos
        bool seguir = true;
        while (seguir) {
            int selecion;
            cout << "0) Salir " << endl;
            cout << "1) Sumar Vector" << endl;
            cout << "2) Promedio del Vector" << endl;
            cout << "3) Moda del Vector" << endl;
            cout << "4) Contar elementos del Vector" << endl;
            cout << "5) Crear archivo txt" << endl;
            cout << "6) Escribir en archivo txt" << endl;
            cout << "##############################" << endl;
            cout << "Seleccione una opcion: ";
            cin >> selecion;
            switch (selecion)
            {
                // Salir
            case 0: {
                seguir = false;
                cout << "A salido del programa" << endl;
                break;
            }
                  // Sumar
            case 1: {
                if (find(permisosInt.begin(), permisosInt.end(), 1) != permisosInt.end()) {
                    int suma = sumaVector(vectorUserInt);
                    cout << "1.- La suma del vector es: " << suma << endl;
                }
                else {
                    cout << "No tiene este permiso" << endl;
                }
                break;
            }
                  // Promedio
            case 2: {
                if (find(permisosInt.begin(), permisosInt.end(), 2) != permisosInt.end()) {
                    float promedio = promedioVector(vectorUserInt);
                    cout << "2.- El promedio del vector es: " << promedio << endl;
                }
                else {
                    cout << "No tiene este permiso" << endl;
                }
                break;
            }
                  // Moda
            case 3: {
                if (find(permisosInt.begin(), permisosInt.end(), 3) != permisosInt.end()) {
                    int moda = modaVector(vectorUserInt);
                    cout << "3.- La moda del vector es: " << moda << endl;
                }
                else {
                    cout << "No tiene este permiso" << endl;
                }
                break;
            }
                  // Contar
            case 4: {
                if (find(permisosInt.begin(), permisosInt.end(), 4) != permisosInt.end()) {
                    int cantidad = contarVector(vectorUserInt);
                    cout << "4.- El vector tiene " << cantidad << " numeros" << endl;
                }
                else {
                    cout << "No tiene este permiso" << endl;
                }
                break;
            }
                  // Crear archivo
            case 5: {
                if (find(permisosInt.begin(), permisosInt.end(), 5) != permisosInt.end()) {
                    if (verificarArchivo(path) == false) {
                        crearArchivo(path);
                        cout << "El archivo fue creado" << endl;
                    }
                    else {
                        cout << "El archivo ya existe" << endl;
                    }

                }
                else {
                    cout << "No tiene este permiso" << endl;
                }
                break;
            }
                  // Escribir en archivo
            case 6: {
                if (find(permisosInt.begin(), permisosInt.end(), 6) != permisosInt.end()) {
                    if (verificarArchivo(path) == false){
                        cout << "El archivo aun no ha sido creado" << endl;
                    }else{
                    escribirArchivo(path, texto);
                    }
                }
                else {
                    cout << "No tiene este permiso" << endl;

                }
                break;
            }
            default: {
                cout << "Esta funcionalidad no esta implementada" << endl;
            }
            }
            cout << "##############################" << endl;
        }

    }

    // for (int i = 0; i < vectorUserInt.size(); ++i)
    // {
    //     cout << vectorUserInt[i] << endl;
    // }
}

// Funciones
int sumaVector(vector<int> v1)
{
    int suma = 0;
    for (int val1 : v1)
    {
        suma += val1;
    }
    return suma;
}

float promedioVector(vector<int> v1)
{
    float suma = sumaVector(v1);
    return suma / v1.size();
}

int modaVector(vector<int> v1)
{
    unordered_map<int, int> frecuencia;

    for (int num : v1)
    {
        frecuencia[num]++;
    }

    int moda = v1[0];
    int maxFrecuencia = 0;

    for (const auto& pair : frecuencia)
    {
        if (pair.second > maxFrecuencia)
        {
            moda = pair.first;
            maxFrecuencia = pair.second;
        }
    }

    return moda;
}

int contarVector(vector<int> v1)
{
    return v1.size();
}

void crearArchivo(string path) {
    ofstream file(path);
    file.open(path);
    file.close();
}

bool verificarArchivo(string path) {
    ifstream file(path);
    return file.good();
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

vector<vector<string>> cargarTexto(string nombreTxt)
{
    string lineaTxt;
    ifstream usersTxt(nombreTxt);
    if (usersTxt.is_open())
    {
        // leo el txt linea a linea
        while (getline(usersTxt, lineaTxt))
        {
            // cout << lineaTxt << endl;
        }
        usersTxt.close();
    }

    // vector donde estaran los usuarios, cada vector adentro estara user,num,num,...,num
    vector<vector<string>> usuarios;

    // separo las cuentas por ;
    vector<string> cuentas;
    istringstream stream(lineaTxt);
    string cuenta;

    while (getline(stream, cuenta, ';'))
    {
        cuentas.push_back(cuenta);
    }

    // separo los users de los permisos (en la primera posicion estara el user y luego los permisos)
    // recorro el vector con las cuentas
    for (int i = 0; i < cuentas.size(); ++i)
    {
        vector<string> useryPermisos;
        istringstream stream(cuentas[i]);
        string temporal;
        while (getline(stream, temporal, ','))
        {
            useryPermisos.push_back(temporal);
        }
        usuarios.push_back(useryPermisos);
    }

    // for (int  i = 0; i < usuarios.size(); ++i) {
    //     for (int  j = 0; j < usuarios[i].size(); ++j){
    //         cout << usuarios[i][j] << " " << endl;
    //     }
    // }

    return usuarios;
}