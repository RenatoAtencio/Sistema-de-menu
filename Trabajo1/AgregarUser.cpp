#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string nombreArchivo = "users.txt";
    string textoOriginal;
    ifstream usersTxt(nombreArchivo);

    if (usersTxt.is_open())
    {
        // leo el txt linea a linea
        while (getline(usersTxt, textoOriginal))
        {
            // cout << lineaTxt << endl;
        }
        usersTxt.close();
    }
    
    textoOriginal = textoOriginal + ";Kylian,1,2,4";
    ofstream archivo;
    archivo.open(nombreArchivo.c_str(),fstream::out);
    archivo << textoOriginal;
    return -1;
}