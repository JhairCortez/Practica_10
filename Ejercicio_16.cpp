#include <iostream>
using namespace std;

int longitud(char* c) {
    int l = 0;
    while (c[l] != '\0')
        l++;
    return l;
}

void invertir(char* c) {
    int l = longitud(c);
    for (int i = 0; i < l / 2; i++) {
        char temp = c[i];
        c[i] = c[l - 1 - i];
        c[l - 1 - i] = temp;
    }
}

int main() {
    char c[100];
    cout << "Ingrese una cadena: ";
    cin.getline(c, 100);

    invertir(c);

    cout << "Cadena invertida: " << c << endl;
}
