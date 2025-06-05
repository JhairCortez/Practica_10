#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenar(int m[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] = rand() % 10;
}

void mostrar(int m[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void sumar(int a[4][4], int b[4][4], int r[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i][j] = a[i][j] + b[i][j];
}

void restar(int a[4][4], int b[4][4], int r[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i][j] = a[i][j] - b[i][j];
}

void multiplicar(int a[4][4], int b[4][4], int r[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            r[i][j] = 0;
            for (int k = 0; k < 4; k++)
                r[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    srand(time(0));

    int a[4][4], b[4][4], s[4][4], r[4][4], p[4][4];

    llenar(a);
    llenar(b);

    cout << "Matriz A:" << endl;
    mostrar(a);

    cout << "Matriz B:" << endl;
    mostrar(b);

    sumar(a, b, s);
    cout << "Suma:" << endl;
    mostrar(s);

    restar(a, b, r);
    cout << "Resta:" << endl;
    mostrar(r);

    multiplicar(a, b, p);
    cout << "Producto:" << endl;
    mostrar(p);
}
