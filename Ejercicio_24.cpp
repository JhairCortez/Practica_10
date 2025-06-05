#include <iostream>
using namespace std;

void generarVector(int v[], int n) {
    int valor = 7;
    for (int i = 0; i < n; i++) {
        v[i] = valor;
        if (i < n / 2) {
            valor--;
        } else {
            valor++;
        }
    }
}

void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 15;
    int vector[n];
    generarVector(vector, n);
    mostrarVector(vector, n);
}
