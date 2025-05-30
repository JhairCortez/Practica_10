#include <iostream>
using namespace std;

void generarLinea(int n) {
    for (int i = 1; i <= n; i++)
        cout << i;
    for (int i = n - 1; i >= 1; i--)
        cout << i;
    cout << endl;
}
void generarSecuencia(int N) {
    for (int i = 2; i <= N + 1; i++)
        generarLinea(i - 1);
}
int main() 
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    generarSecuencia(N);
}
