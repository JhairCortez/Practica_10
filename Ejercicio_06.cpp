#include <iostream>
using namespace std;

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int obtenerDias(int mes, int anio) {
    if (mes < 1 || mes > 12) return -1;
    if (mes == 2)
        return esBisiesto(anio) ? 29 : 28;
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;
    else
        return 31;
}

int main() 
{
    int mes, anio;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    int dias = obtenerDias(mes, anio);
    if (dias == -1)
        cout << "Mes invalido." << endl;
    else
        cout << "El mes tiene " << dias << " dias." << endl;
}
