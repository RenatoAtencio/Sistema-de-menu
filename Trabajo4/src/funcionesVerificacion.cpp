#include "../include/funciones.h"

using namespace std;

// Verifica la existencia de un archivo, toma el path completo menos el root (en este caso Trabajo4)
bool verificarArchivo(string path){
    string pathCompleto = "../" + path;
    ifstream file(pathCompleto);
    cout<< pathCompleto << " " << file.good() << " ";
    return (file.good());
}