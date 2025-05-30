#include <iostream>
using namespace std;

int invertirNumero(int num) {
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}
int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    cout << "Numero invertido: " << invertirNumero(numero) << endl;
}
