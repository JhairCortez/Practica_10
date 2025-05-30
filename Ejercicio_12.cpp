#include <iostream>
#include <string>
using namespace std;

void repetirDigitos(const string& numero) {
    for (char c : numero) {
        int digito = c - '0';
        for (int i = 0; i < digito; i++) {
            cout << digito;
        }
    }
    cout << endl;
}
int main() {
    string numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    repetirDigitos(numero);
}
