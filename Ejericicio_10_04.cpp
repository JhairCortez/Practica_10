// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 4
// Problema planteado: Personal de la UCB
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado 
{
    string nombre;
    string genero;
    double salario;
};

void registrarEmpleado(Empleado &empleado) 
{
    cout << "Ingrese el nombre del empleado: ";
    getline(cin, empleado.nombre);
    cout << "Ingrese el género del empleado: ";
    getline(cin, empleado.genero);
    cout << "Ingrese el salario del empleado: ";
    cin >> empleado.salario;
    if (empleado.salario < 0) 
    {
        cin.ignore();
        cout << "Salario inválido. Intente nuevamente.\n";
        registrarEmpleado(empleado);
        return;
    }
    cin.ignore();
}

Empleado encontrarMayorSalario(const vector<Empleado> &empleados, int indice, Empleado mayor) 
{
    if (indice == empleados.size()) 
    {
        return mayor;
    }
    if (empleados[indice].salario > mayor.salario) 
    {
        mayor = empleados[indice];
    }
    return encontrarMayorSalario(empleados, indice + 1, mayor);
}

Empleado encontrarMenorSalario(const vector<Empleado> &empleados, int indice, Empleado menor) 
{
    if (indice == empleados.size()) 
    {
        return menor;
    }
    if (empleados[indice].salario < menor.salario) 
    {
        menor = empleados[indice];
    }
    return encontrarMenorSalario(empleados, indice + 1, menor);
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
    Empleado mayorSalario = encontrarMayorSalario(empleados, 0, empleados[0]);
    Empleado menorSalario = encontrarMenorSalario(empleados, 0, empleados[0]);
    cout << "\n--- Empleado con mayor salario ---\n";
    cout << "Nombre: " << mayorSalario.nombre << endl;
    cout << "Género: " << mayorSalario.genero << endl;
    cout << "Salario: " << mayorSalario.salario << endl;
    cout << "\n--- Empleado con menor salario ---\n";
    cout << "Nombre: " << menorSalario.nombre << endl;
    cout << "Género: " << menorSalario.genero << endl;
    cout << "Salario: " << menorSalario.salario << endl;
    return 0;
}