#include "funciones.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Paso el txt a un vector de vectores, cada vector sera un usuario y sus permisos (todo en string)
    vector<vector<string>> usuarios;
    usuarios = cargarTexto("users.txt");

    // Entrada en la consola, paso los valores de las flags a su respectiva variable
    char c;
    string texto, path, respuesta, vectorUserStr, nombreUser;
    vector<int> vectorUserInt;
    while ((c = getopt(argc, argv, "u:v:f:t:")) != -1) {
        switch (c) {
        case 'u': { // user
            nombreUser = optarg;
            break;
        }
        case 'v': { // vector 
            vectorUserStr = optarg;
            vectorUserInt = stringSepararPorComa(vectorUserStr);
            break;
        }
        case 'f': { // path
            path = optarg;
            break;
        }
        case 't': { // texto
            texto = optarg;
            break;
        }
        }
    }

    // Verificar si el usuario esta en la base de datos, es case sensitive, el i sera en index si existe
    int i = 0;
    if (verificarUsuario(usuarios, i, nombreUser) == false) {
        cout << "Usuario no esta registrado" << endl;
    }
    // Si el usuario si existe
    else {
        // Creo el vector de los permisos pero en int
        usuario user = crearUsuario(i, usuarios, vectorUserInt);
        // Muestro el menu
        mostrarMenu();
        // Preguntar opciones y mostrar segun el caso
        bool seguir = true;
        while (seguir) {
            int selecion;
            cout << "Seleccione una opcion: ";
            cin >> selecion;
            verSeleccion(selecion,seguir,user,path,texto);
            cout << "##############################" << endl;
        }
    }
}

// Funciones
bool verificarArchivo(string path) {
    ifstream file(path);
    return file.good();
}

vector<vector<string>> cargarTexto(string nombreTxt) {
    string lineaTxt;
    ifstream usersTxt(nombreTxt);
    if (usersTxt.is_open()) {
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

    while (getline(stream, cuenta, ';')) {
        cuentas.push_back(cuenta);
    }
    // separo los users de los permisos (en la primera posicion estara el user y luego los permisos)
    // recorro el vector con las cuentas
    for (int i = 0; i < cuentas.size(); ++i) {
        vector<string> useryPermisos;
        istringstream stream(cuentas[i]);
        string temporal;
        while (getline(stream, temporal, ','))
        {
            useryPermisos.push_back(temporal);
        }
        usuarios.push_back(useryPermisos);
    }
    return usuarios;
}