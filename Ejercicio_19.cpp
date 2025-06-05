#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(int matriz[][20], int filas, int columnas) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = rand() % 10;
}

void mostrarMatriz(int matriz[][20], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void transponerMatriz(int matriz[][20], int transpuesta[][20], int filas, int columnas) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            transpuesta[j][i] = matriz[i][j];
}

int main() {
    srand(time(NULL));
    int filas, columnas;

    do {
        cout << "Ingrese numero de filas (2-20): ";
        cin >> filas;
    } while (filas < 2 || filas > 20);

    do {
        cout << "Ingrese numero de columnas (2-20): ";
        cin >> columnas;
    } while (columnas < 2 || columnas > 20);

    int matriz[20][20], transpuesta[20][20];

    llenarMatriz(matriz, filas, columnas);

    cout << "Matriz original:\n";
    mostrarMatriz(matriz, filas, columnas);

    transponerMatriz(matriz, transpuesta, filas, columnas);

    cout << "Matriz transpuesta:\n";
    mostrarMatriz(transpuesta, columnas, filas);
}
