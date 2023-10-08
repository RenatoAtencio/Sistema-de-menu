#include "../include/funciones.h"

using namespace std;

void verSeleccion(bool& seguir, usuario user, int userInput, string nombreNuevoTxt, string textoNuevoTxt, string nombreTexto, string nombreArchivoSalidaConteo) {
    switch (userInput) {
    case 0: { // Salir
        seguir = false;
        user.salir();
        break;
    }
    case 1: { // Sumar
        if (user.verificarPermiso(1)) {
            int suma = user.sumaVector();
            cout << "1.- La suma del vector es: " << suma << endl;
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 2: { // Promedio
        if (user.verificarPermiso(2)) {
            float promedio = user.promedioVector();
            cout << "2.- El promedio del vector es: " << promedio << endl;
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 3: { // Moda
        if (user.verificarPermiso(3)) {
            int moda = user.modaVector();
            cout << "3.- La moda del vector es: " << moda << endl;
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 4: { // Contar
        if (user.verificarPermiso(4)) {
            int cantidad = user.contarVector();
            cout << "4.- El vector tiene " << cantidad << " numeros" << endl;
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 5: { // Crear archivo
        if (user.verificarPermiso(5)) {
            string pathNuevoArchivo = string(getenv("PATH_OUTPUTFILES")) + nombreNuevoTxt;
            if (verificarArchivo(pathNuevoArchivo) == false) {
                user.crearArchivo(pathNuevoArchivo);
                cout << "5.- El archivo fue creado" << endl;
            }
            else {
                cout << "5.- El archivo ya existe" << endl;
            }
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 6: { // Escribir en archivo
        if (user.verificarPermiso(6)) {
            string pathNuevoArchivo = getenv("PATH_OUTPUTFILES") + nombreNuevoTxt;
            if (verificarArchivo(pathNuevoArchivo) == false) {
                cout << "6.- El archivo aun no ha sido creado" << endl;
            }
            else {
                user.escribirArchivo(pathNuevoArchivo, textoNuevoTxt);
            }
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 7: { // Contar Palabras
        if (user.verificarPermiso(7)) {
            string pathTexto = getenv("PATH_RAWFILES") + nombreTexto;
            if (verificarArchivo(pathTexto) == false) {
                cout << "El archivo no existe" << endl;
            }
            else {
                user.contarPalabras(nombreTexto,nombreArchivoSalidaConteo);
            }
            break;
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
    default: { // Cualquier otro caso
        cout << "Esta funcionalidad no esta implementada" << endl;
    }
    }
    }
}

void mostrarMenu() {
    ifstream menu(getenv("DB_MENU"));
    vector<vector<string>> opciones(8);
    string linea;
    while (getline(menu, linea)) {
        vector<string> v1;
        v1 = separarStringPorComaVectorString(linea);
        int opcion = stoi(v1[1]);
        opciones[opcion] = v1;
    }
    for (int i = 0; i < opciones.size();i++) {
        cout << opciones[i][0] << endl;
    }
}
