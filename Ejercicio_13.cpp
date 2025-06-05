#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(int m[20][20], int f, int c) {
    srand(time(0));
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            m[i][j] = rand() % 10;
}
void mostrarMatriz(int m[20][20], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}
void transponerMatriz(int m[20][20], int t[20][20], int f, int c) {
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = m[i][j];
}
int main() {
    int filas, columnas;
    cout << "Ingrese filas (2-20): ";
    cin >> filas;
    cout << "Ingrese columnas (2-20): ";
    cin >> columnas;
    if (filas < 2 || filas > 20 || columnas < 2 || columnas > 20) {
        cout << "Valores fuera de rango." << endl;
    } else {
        int matriz[20][20], transpuesta[20][20];
        llenarMatriz(matriz, filas, columnas);
        cout << "Matriz original:" << endl;
        mostrarMatriz(matriz, filas, columnas);
        transponerMatriz(matriz, transpuesta, filas, columnas);
        cout << "Matriz transpuesta:" << endl;
        mostrarMatriz(transpuesta, columnas, filas);
    }
}
