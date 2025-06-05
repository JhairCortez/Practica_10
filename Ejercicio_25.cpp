#include <iostream>
using namespace std;

void llenarMatriz(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = i + 1;
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
