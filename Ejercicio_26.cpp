#include <iostream>
using namespace std;

void llenarMatriz(int matriz[10][10]) {
    int cont = 1;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            // Filas pares: números del 1 al 10
            for (int j = 0; j < 10; j++) {
                matriz[i][j] = j + 1;
            }
        } else {
            // Filas impares: números decrecientes desde 109 - 10*i
            int start = 109 - (i / 2) * 10;
            for (int j = 0; j < 10; j++) {
                matriz[i][j] = start - j;
            }
        }
    }
}

void mostrarMatriz(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[10][10];
    llenarMatriz(matriz);
    mostrarMatriz(matriz);
}
