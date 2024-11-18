// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 8
// Problema planteado: Olimpiada Nacional
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Atleta 
{
    string nombre;
    string departamento;
    string deporte;
    int medallas;
};

void registrarAtleta(Atleta &atleta, const vector<string> &deportes) 
{
    cout << "Ingrese el nombre del atleta: ";
    getline(cin, atleta.nombre);
    cout << "Ingrese el departamento que representa: ";
    getline(cin, atleta.departamento);
    cout << "Seleccione el deporte que practica:\n";
    for (size_t i = 0; i < deportes.size(); i++) 
    {
        cout << i + 1 << ". " << deportes[i] << endl;
    }
    int opcion;
    cin >> opcion;
    cin.ignore();
    if (opcion < 1 || opcion > deportes.size()) 
    {
        cout << "Deporte inválido. Intente nuevamente.\n";
        registrarAtleta(atleta, deportes);
        return;
    }
    atleta.deporte = deportes[opcion - 1];
    cout << "Ingrese la cantidad de medallas ganadas por este atleta: ";
    cin >> atleta.medallas;
    if (atleta.medallas < 0) 
    {
        cout << "Cantidad de medallas inválida. Intente nuevamente.\n";
        cin.ignore();
        registrarAtleta(atleta, deportes);
        return;
    }
    cin.ignore();
}

map<string, int> calcularMedalleroPorDepartamento(const vector<Atleta> &atletas) 
{
    map<string, int> medallero;
    for (const Atleta &atleta : atletas) {
        medallero[atleta.departamento] += atleta.medallas;
    }
    return medallero;
}

void mostrarMedallero(const map<string, int> &medallero) 
{
    cout << "\n--- Medallero Final ---\n";
    for (const auto &entry : medallero) 
    {
        cout << "Departamento: " << entry.first << " - Medallas: " << entry.second << endl;
    }
}

int main() 
{
    vector<string> deportes = 
    {
        "Tiro con arco", "Atletismo", "Boxeo", "Ciclismo", "Natación", "Esgrima"
    };
    int n;
    cout << "Ingrese la cantidad de atletas a registrar: ";
    cin >> n;
    cin.ignore();
    vector<Atleta> atletas(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos del atleta " << i + 1 << ":\n";
        registrarAtleta(atletas[i], deportes);
    }
    map<string, int> medallero = calcularMedalleroPorDepartamento(atletas);
    mostrarMedallero(medallero);
    return 0;
}