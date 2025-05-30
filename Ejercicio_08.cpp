#include <iostream>
using namespace std;

int sumaDivisores(int n, int d = 1) {
    if (d == n) return 0;
    return (n % d == 0 ? d : 0) + sumaDivisores(n, d + 1);
}

bool esPerfecto(int n) {
    return sumaDivisores(n) == n;
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    if (esPerfecto(n))
        cout << "El numero es PERFECTO." << endl;
    else
        cout << "El numero NO es perfecto." << endl;
}
