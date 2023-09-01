#include "funciones.h"
#include <vector>
#include <string>

using namespace std;

bool verificarUsuario(vector<vector<string>> usuarios, int& index, string nombreUsuario) {
    while (index < usuarios.size() && nombreUsuario != usuarios[index][0]) {
        index++;
    }
    if (index == usuarios.size()) {
        return false;
    }
    return true;
}

usuario crearUsuario(int index, vector<vector<string>> usuarios, vector<int> vectorUserInt) {
    vector<int> permisosInt;
    permisosInt = vectorstoi(usuarios[index]);
    usuario user(usuarios[index][0], vectorUserInt, permisosInt);
    return user;
}