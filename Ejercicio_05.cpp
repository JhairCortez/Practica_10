#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string convertirAMinusculas(string palabra) {
    for (int i = 0; i < palabra.length(); i++)
        palabra[i] = tolower(palabra[i]);
    return palabra;
}
int main() 
{
    string palabra;
    cout << "Ingrese una palabra en mayúsculas: ";
    cin >> palabra;
    string minuscula = convertirAMinusculas(palabra);
    cout << "En minúsculas: " << minuscula << endl;
}
