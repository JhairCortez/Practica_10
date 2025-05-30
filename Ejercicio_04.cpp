#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string convertirAMayusculas(string palabra) {
    for (int i = 0; i < palabra.length(); i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}
int main() {
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    string mayuscula = convertirAMayusculas(palabra);
    cout << "En mayúsculas: " << mayuscula << endl;
}
