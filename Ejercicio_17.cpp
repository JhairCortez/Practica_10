#include <iostream>
using namespace std;

void mostrarLinea(int n) {
    for (int i = 1; i <= n; i++)
        cout << i;
    for (int i = n - 1; i >= 1; i--)
        cout << i;
    cout << endl;
}

int main() {
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 2; i <= N + 1; i++)
        mostrarLinea(i - 1);
}
