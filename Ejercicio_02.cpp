#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char encriptarCaracter(char c) {
    switch (tolower(c)) {
        case 'a': return '1';
        case 'e': return '2';
        case 'i': return '3';
        case 'o': return '4';
        case 'u': return '5';
        case ' ': return '8';
        default: return c;
    }
}

string encriptarFrase(string frase) {
    string resultado = "";
    for (char c : frase) {
        resultado += encriptarCaracter(c);
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    string encriptado = encriptarFrase(frase);
    cout << "Frase encriptada e invertida: " << encriptado << endl;

    return 0;
}
