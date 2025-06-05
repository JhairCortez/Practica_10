#include <iostream>
#include <cmath>
using namespace std;

double calcularCatetoOpuesto(double hipotenusa, double catetoAdyacente) {
    return sqrt(pow(hipotenusa, 2) - pow(catetoAdyacente, 2));
}

double calcularCatetoAdyacente(double hipotenusa, double catetoOpuesto) {
    return sqrt(pow(hipotenusa, 2) - pow(catetoOpuesto, 2));
}

double calcularHipotenusa(double catetoOpuesto, double catetoAdyacente) {
    return sqrt(pow(catetoOpuesto, 2) + pow(catetoAdyacente, 2));
}

int main() {
    int opcion;
    double hipotenusa, catetoOpuesto, catetoAdyacente;

    cout << "Menu:\n";
    cout << "1.- Calcular cateto opuesto\n";
    cout << "2.- Calcular cateto adyacente\n";
    cout << "3.- Calcular hipotenusa\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            cout << "Ingrese hipotenusa: ";
            cin >> hipotenusa;
            cout << "Ingrese cateto adyacente: ";
            cin >> catetoAdyacente;
            cout << "Cateto opuesto = " << calcularCatetoOpuesto(hipotenusa, catetoAdyacente) << endl;
            break;
        case 2:
            cout << "Ingrese hipotenusa: ";
            cin >> hipotenusa;
            cout << "Ingrese cateto opuesto: ";
            cin >> catetoOpuesto;
            cout << "Cateto adyacente = " << calcularCatetoAdyacente(hipotenusa, catetoOpuesto) << endl;
            break;
        case 3:
            cout << "Ingrese cateto opuesto: ";
            cin >> catetoOpuesto;
            cout << "Ingrese cateto adyacente: ";
            cin >> catetoAdyacente;
            cout << "Hipotenusa = " << calcularHipotenusa(catetoOpuesto, catetoAdyacente) << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
}
