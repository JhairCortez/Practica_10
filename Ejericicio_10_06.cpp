// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 6
// Problema planteado: Gestión de empleados con funciones
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado 
{
    string nombre;
    int id;
    double sueldo;
    int antiguedad;
};

void registrarEmpleado(Empleado &empleado) 
{
    cout << "Ingrese el nombre del empleado: ";
    getline(cin, empleado.nombre);
    cout << "Ingrese el ID del empleado: ";
    cin >> empleado.id;
    if (empleado.id <= 0) 
    {
        cin.ignore();
        cout << "ID inválido. Intente nuevamente.\n";
        registrarEmpleado(empleado);
        return;
    }
    cout << "Ingrese el sueldo del empleado: ";
    cin >> empleado.sueldo;

    if (empleado.sueldo < 0) 
    {
        cin.ignore();
        cout << "Sueldo inválido. Intente nuevamente.\n";
        registrarEmpleado(empleado);
        return;
    }
    cout << "Ingrese la antigüedad del empleado (en años): ";
    cin >> empleado.antiguedad;
    if (empleado.antiguedad < 0) 
    {
        cin.ignore();
        cout << "Antigüedad inválida. Intente nuevamente.\n";
        registrarEmpleado(empleado);
        return;
    }
    cin.ignore();
}

int contarEmpleadosConSueldoMayor(const vector<Empleado> &empleados, double sueldo) 
{
    int contador = 0;
    for (const Empleado &empleado : empleados) 
    {
        if (empleado.sueldo > sueldo) 
        {
            contador++;
        }
    }
    return contador;
}

double calcularPromedioAntiguedad(const vector<Empleado> &empleados) 
{
    int totalAntiguedad = 0;
    for (const Empleado &empleado : empleados) 
    {
        totalAntiguedad += empleado.antiguedad;
    }
    return static_cast<double>(totalAntiguedad) / empleados.size();
}

int main() 
{
    int n;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;
    cin.ignore();
    vector<Empleado> empleados(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos del empleado " << i + 1 << ":\n";
        registrarEmpleado(empleados[i]);
    }
    double sueldoCriterio;
    cout << "\nIngrese un sueldo para contar empleados con sueldo mayor: ";
    cin >> sueldoCriterio;
    int cantidad = contarEmpleadosConSueldoMayor(empleados, sueldoCriterio);
    cout << "Cantidad de empleados con sueldo mayor a " << sueldoCriterio << ": " << cantidad << endl;
    double promedioAntiguedad = calcularPromedioAntiguedad(empleados);
    cout << "El promedio de antigüedad de los empleados es: " << promedioAntiguedad << " años.\n";
    return 0;
}