#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Usuario.cpp"
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
#include <map>
#include <cctype>



using namespace std;

// funciones de parse (funcionesParse.cpp)
vector<int> separarStringPorComaVectorInt(string secuencia);
vector<string> separarStringPorComaVectorString(string linea);
vector<int> vectorstoi(vector<string> vectorString);

// funciones para usuario (funcionesParaUsuario.cpp)
usuario crearUsuario(int index, vector<vector<string>> usuarios, vector<int> vectorUserInt);
bool verificarUsuario(vector<vector<string>> usuarios, int& index, string nombreUsuario);

// funciones de menu (funcionesMenu.cpp)
void mostrarMenu();
void verSeleccion(int userInput, bool& seguir, usuario user, string pathCrearArchivo, string pathTexto,string pathSalidaConteo, string textoArchivo);

// funciones de archivo (main.cpp)
bool verificarArchivo(string path);

// funciones de bd (main.cpp)
vector<vector<string>> separarTextoFormatoNormal(string pathArchivo);

#endif