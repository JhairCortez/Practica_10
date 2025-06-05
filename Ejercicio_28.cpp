#include <iostream>
using namespace std;

void llenarEspiral(int matriz[10][10]) {
    int valor = 1, minFila = 0, maxFila = 9, minCol = 0, maxCol = 9;
    while (valor <= 100) {
        for (int j = minCol; j <= maxCol; j++)
            matriz[minFila][j] = valor++;
        minFila++;
        for (int i = minFila; i <= maxFila; i++)
            matriz[i][maxCol] = valor++;
        maxCol--;
        for (int j = maxCol; j >= minCol; j--)
            matriz[maxFila][j] = valor++;
        maxFila--;
        for (int i = maxFila; i >= minFila; i--)
            matriz[i][minCol] = valor++;
        minCol++;
    }
}

void mostrarMultiplosDe5(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] % 5 == 0)
                cout << matriz[i][j] << "\t";
            else
                cout << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matriz[10][10];
    llenarEspiral(matriz);
    mostrarMultiplosDe5(matriz);
}
