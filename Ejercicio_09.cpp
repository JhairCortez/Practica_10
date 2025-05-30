#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord = {short(x), short(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarPiramide() {
    int fila = 2;
    int columnaCentral = 50;
    for (int i = 0; i < 5; i++) {
        int numAsteriscos = 2 * i + 1;
        int columnaInicio = columnaCentral - i;
        gotoxy(columnaInicio, fila + i);
        for (int j = 0; j < numAsteriscos; j++)
            cout << "*";
    }
}
int main() {
    dibujarPiramide();
}
