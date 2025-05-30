#include <iostream>
using namespace std;

int sumaDigitos(int n) {
    if (n < 10) return n;
    return n % 10 + sumaDigitos(n / 10);
}

bool divisiblePorSuma(int n) {
    int suma = sumaDigitos(n);
    return n % suma == 0;
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    if (divisiblePorSuma(n))
        cout << "El numero es divisible por la suma de sus digitos." << endl;
    else
        cout << "El numero NO es divisible por la suma de sus digitos." << endl;
}
