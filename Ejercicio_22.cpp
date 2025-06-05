#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void crearArchivo() {
    ofstream archivo("DATOS01.TXT");
    srand(time(NULL));
    for (int i = 0; i < 200; i++) {
        char letra = 'A' + rand() % 26;
        archivo << letra << '\n';
    }
    archivo.close();
}

void mostrarArchivo(const string& nombre) {
    ifstream archivo(nombre);
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void archivoAVector(const string& nombre, vector<char>& vec) {
    ifstream archivo(nombre);
    char c;
    vec.clear();
    while (archivo >> c) {
        vec.push_back(c);
    }
    archivo.close();
}

void ordenarVector(vector<char>& vec) {
    sort(vec.begin(), vec.end());
}

void vectorAArchivo(const string& nombre, const vector<char>& vec) {
    ofstream archivo(nombre);
    for (char c : vec) {
        archivo << c << '\n';
    }
    archivo.close();
}

int main() {
    vector<char> vec;
    
    crearArchivo();
    cout << "Contenido de DATOS01.TXT:" << endl;
    mostrarArchivo("DATOS01.TXT");

    archivoAVector("DATOS01.TXT", vec);
    ordenarVector(vec);
    vectorAArchivo("DATOS02.TXT", vec);

    cout << "\nContenido de DATOS02.TXT (ordenado):" << endl;
    mostrarArchivo("DATOS02.TXT");
}
