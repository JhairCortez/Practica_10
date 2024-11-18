// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 3
// Problema planteado: Estudiantes de Programación
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Estudiante 
{
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string profesion;
    string lugar_nacimiento;
    string direccion;
    int telefono;
};

void registrarEstudiante(Estudiante &estudiante) 
{
    cout << "Ingrese la cédula del estudiante: ";
    cin >> estudiante.cedula;
    if (estudiante.cedula <= 0) 
    {
        cin.ignore();
        cout << "Cédula inválida. Intente nuevamente.\n";
        registrarEstudiante(estudiante);
        return;
    }
    cin.ignore();
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, estudiante.nombre);
    cout << "Ingrese el apellido del estudiante: ";
    getline(cin, estudiante.apellido);
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    if (estudiante.edad <= 0) 
    {
        cin.ignore();
        cout << "Edad inválida. Intente nuevamente.\n";
        registrarEstudiante(estudiante);
        return;
    }
    cin.ignore();
    cout << "Ingrese la profesión del estudiante: ";
    getline(cin, estudiante.profesion);
    cout << "Ingrese el lugar de nacimiento del estudiante: ";
    getline(cin, estudiante.lugar_nacimiento);
    cout << "Ingrese la dirección del estudiante: ";
    getline(cin, estudiante.direccion);
    cout << "Ingrese el teléfono del estudiante: ";
    cin >> estudiante.telefono;
    if (estudiante.telefono <= 0) 
    {
        cin.ignore();
        cout << "Teléfono inválido. Intente nuevamente.\n";
        registrarEstudiante(estudiante);
        return;
    }

    cin.ignore();
}

void mostrarEstudiante(const Estudiante &estudiante) 
{
    cout << "\n--- Datos del Estudiante ---\n";
    cout << "Cédula: " << estudiante.cedula << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Apellido: " << estudiante.apellido << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Profesión: " << estudiante.profesion << endl;
    cout << "Lugar de Nacimiento: " << estudiante.lugar_nacimiento << endl;
    cout << "Dirección: " << estudiante.direccion << endl;
    cout << "Teléfono: " << estudiante.telefono << endl;
}

int main() 
{
    int n;
    cout << "Ingrese el número de estudiantes: ";
    cin >> n;
    cin.ignore();
    vector<Estudiante> estudiantes(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos del estudiante " << i + 1 << ":\n";
        registrarEstudiante(estudiantes[i]);
    }
    cout << "\n--- Datos de todos los estudiantes ---\n";
    for (int i = 0; i < n; i++) 
    {
        mostrarEstudiante(estudiantes[i]);
    }
    return 0;
}