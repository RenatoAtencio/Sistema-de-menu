#include "funciones.h"

using namespace std;

void verSeleccion(int userInput, bool& seguir, usuario user, string pathCrearArchivo, string pathTexto, string pathSalidaConteo, string textoArchivo) {
    switch (userInput) {
    case 0: { // Salir
        seguir = false;
        // si uno usa 7 y sale el archivo temporal debe eliminarse
        remove(getenv("PATH_CUENTO_TEMPORAL"));
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
            if (verificarArchivo(pathCrearArchivo) == false) {
                user.crearArchivo(pathCrearArchivo);
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
            if (verificarArchivo(pathCrearArchivo) == false) {
                cout << "6.- El archivo aun no ha sido creado" << endl;
            }
            else {
                user.escribirArchivo(pathCrearArchivo, textoArchivo);
            }
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 7: { // Cargar archivo para contar y crea un archivo temporal sin la mayoria de puntuaciones
        if (user.verificarPermiso(7)) {
            if (verificarArchivo(pathTexto) && (verificarArchivo(getenv("PATH_CUENTO_TEMPORAL")) == false)) {
                cout << "7.- se creo un nuevo archivo sin puntuaciones" << endl;
                user.crearCuentoSinPuntuacion(pathTexto);
            }
            else if (verificarArchivo(pathTexto) == false) {
                cout << "7.- El archivo de entrada no existe" << endl;
            }
            else {
                cout << "7.- El archivo temporal aun existe" << endl;
            }
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 8: { // Contar palabras en el archivo sin puntuacion, lo elimina al terminar
        if (user.verificarPermiso(8)) {
            if (verificarArchivo(getenv("PATH_CUENTO_TEMPORAL")) == false) {
                cout << "8.- Aun no se crea el archivo sin puntuaciones (usar 7)" << endl;
            }
            else {
                user.contarPalabras(pathSalidaConteo);
                cout << "8.- Se creo la el archivo salida.txt con la respuesta" << endl;
                remove(getenv("PATH_CUENTO_TEMPORAL"));
                cout << "    Se elimino el archivo temporal" << endl;
            }
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    default: { // Cualquier otro caso
        cout << "Esta funcionalidad no esta implementada" << endl;
    }
    }
}

void mostrarMenu() {
    ifstream menu(getenv("DB_MENU"));
    vector<vector<string>> opciones(9);
    string linea;
    while (getline(menu, linea)) {
        vector v1 = separarStringPorComaVectorString(linea);
        int opcion = stoi(v1[1]);
        opciones[opcion] = v1;
    }
    for (int i = 0; i < opciones.size();i++) {
        cout << opciones[i][0] << endl;
    }
}
