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

void sumarMatrices(int a[4][4], int b[4][4], int suma[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            suma[i][j] = a[i][j] + b[i][j];
}

void restarMatrices(int a[4][4], int b[4][4], int resta[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            resta[i][j] = a[i][j] - b[i][j];
}

void multiplicarMatrices(int a[4][4], int b[4][4], int producto[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            producto[i][j] = 0;
            for (int k = 0; k < 4; k++)
                producto[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    srand(time(NULL));
    int a[4][4], b[4][4], suma[4][4], resta[4][4], producto[4][4];

    llenarMatriz(a);
    llenarMatriz(b);

    cout << "Matriz A:\n";
    mostrarMatriz(a);

    cout << "Matriz B:\n";
    mostrarMatriz(b);

    sumarMatrices(a, b, suma);
    restarMatrices(a, b, resta);
    multiplicarMatrices(a, b, producto);

    cout << "Suma:\n";
    mostrarMatriz(suma);

    cout << "Resta:\n";
    mostrarMatriz(resta);

    cout << "Producto:\n";
    mostrarMatriz(producto);
}
