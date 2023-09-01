#include "funciones.h"

using namespace std;

void verSeleccion(int userInput, bool& seguir, usuario user, string path, string texto) {
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
            if (verificarArchivo(path) == false) {
                user.crearArchivo(path);
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
    case 6: { // Escribir en archivo
        if (user.verificarPermiso(6)) {
            if (verificarArchivo(path) == false) {
                cout << "El archivo aun no ha sido creado" << endl;
            }
            else {
                user.escribirArchivo(path, texto);
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
}

void mostrarMenu() {
    // string menu = "menu.txt";
    // string lineaTxt;
    // ifstream usersTxt(menu);
    // if (usersTxt.is_open()) {
    //     // leo el txt linea a linea
    //     while (getline(usersTxt, lineaTxt))
    //     {
    //         cout << lineaTxt << endl;
    //     }
    //     usersTxt.close();
    // }

    cout << "##########---Menu---##########" << endl;
    cout << "0) Salir " << endl;
    cout << "1) Sumar Vector" << endl;
    cout << "2) Promedio del Vector" << endl;
    cout << "3) Moda del Vector" << endl;
    cout << "4) Contar elementos del Vector" << endl;
    cout << "5) Crear archivo txt" << endl;
    cout << "6) Escribir en archivo txt" << endl;
    cout << "##############################" << endl;

}
