#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matriz[i][j] = rand() % 10;
}

void mostrarMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void sumarMatrices(int A[4][4], int B[4][4], int R[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void restarMatrices(int A[4][4], int B[4][4], int R[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            R[i][j] = A[i][j] - B[i][j];
}

void multiplicarMatrices(int A[4][4], int B[4][4], int R[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            R[i][j] = 0;
            for (int k = 0; k < 4; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    srand(time(0));
    int A[4][4], B[4][4], Suma[4][4], Resta[4][4], Producto[4][4];

    llenarMatriz(A);
    llenarMatriz(B);

    cout << "Matriz A:\n";
    mostrarMatriz(A);
    cout << "Matriz B:\n";
    mostrarMatriz(B);

    sumarMatrices(A, B, Suma);
    cout << "Suma:\n";
    mostrarMatriz(Suma);

    restarMatrices(A, B, Resta);
    cout << "Resta:\n";
    mostrarMatriz(Resta);

    multiplicarMatrices(A, B, Producto);
    cout << "Producto:\n";
    mostrarMatriz(Producto);
}
