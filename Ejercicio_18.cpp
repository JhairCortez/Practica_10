#include <iostream>
#include <string>
using namespace std;

void desplegarRepeticiones(string num) {
    for (char c : num) {
        int digito = c - '0';
        for (int i = 0; i < digito; i++)
            cout << digito;
    }
    cout << endl;
}

int main() {
    string numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    desplegarRepeticiones(numero);
}
