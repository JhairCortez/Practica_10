// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 9
// Problema planteado: Calificaciones Curso
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Alumno 
{
    string nombre;
    double t1, t2, t3, t4, ef, nf;
};

void registrarNotas(Alumno &alumno) 
{
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Ingrese la nota T1: ";
    cin >> alumno.t1;
    cout << "Ingrese la nota T2: ";
    cin >> alumno.t2;
    cout << "Ingrese la nota T3: ";
    cin >> alumno.t3;
    cout << "Ingrese la nota T4: ";
    cin >> alumno.t4;
    cout << "Ingrese la nota EF: ";
    cin >> alumno.ef;
    double np = (alumno.t1 + alumno.t2 + alumno.t3 + alumno.t4) / 4.0;
    alumno.nf = 0.7 * np + 0.3 * alumno.ef;
    cin.ignore(); 
}

double calcularPromedioFinal(const vector<Alumno> &alumnos) 
{
    double suma = 0;
    for (const Alumno &alumno : alumnos) 
    {
        suma += alumno.nf;
    }
    return suma / alumnos.size();
}

void calcularMinMaxFinal(const vector<Alumno> &alumnos, double &min, double &max) 
{
    min = numeric_limits<double>::max();  
    max = numeric_limits<double>::lowest(); 
    for (const Alumno &alumno : alumnos) 
    {
        if (alumno.nf < min) 
        {
            min = alumno.nf;
        }
        if (alumno.nf > max) 
        {
            max = alumno.nf;
        }
    }
}

int main() 
{
    int n;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> n;
    cin.ignore(); 
    vector<Alumno> alumnos(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando notas del alumno " << i + 1 << ":\n";
        registrarNotas(alumnos[i]);
    }
    double promedio = calcularPromedioFinal(alumnos);
    cout << "\nPromedio de las notas finales: " << promedio << endl;
    double min, max;
    calcularMinMaxFinal(alumnos, min, max);
    cout << "Nota mínima final: " << min << endl;
    cout << "Nota máxima final: " << max << endl;
    return 0;
}