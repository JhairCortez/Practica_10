// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 2
// Problema planteado: Datos de un atleta
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Atleta 
{
    string nombre;
    string pais;
    int edad;
    int mejor_tiempo;
};

void registrarAtleta(Atleta &atleta) 
{
    cout << "Ingrese el nombre del atleta: ";
    getline(cin, atleta.nombre);
    cout << "Ingrese el país del atleta: ";
    getline(cin, atleta.pais);
    cout << "Ingrese la edad del atleta: ";
    cin >> atleta.edad;
    if (atleta.edad <= 0) 
    {
        cin.ignore();
        cout << "Edad inválida, por favor intente nuevamente.\n";
        registrarAtleta(atleta);
        return;
    }
    cout << "Ingrese el mejor tiempo del atleta (en segundos): ";
    cin >> atleta.mejor_tiempo;
    if (atleta.mejor_tiempo <= 0) 
    {
        cin.ignore();
        cout << "Tiempo inválido, por favor intente nuevamente.\n";
        registrarAtleta(atleta);
        return;
    }

    cin.ignore();
}

Atleta encontrarMejorAtleta(const vector<Atleta> &atletas, int indice, Atleta mejor)
{
    if (indice == atletas.size()) 
    {
        return mejor;
    }
    if (atletas[indice].mejor_tiempo < mejor.mejor_tiempo) 
    {
        mejor = atletas[indice];
    }
    return encontrarMejorAtleta(atletas, indice + 1, mejor);
}

int main() 
{
    int n;
    cout << "Ingrese la cantidad de atletas: ";
    cin >> n;
    cin.ignore();
    vector<Atleta> atletas(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos del atleta " << i + 1 << ":\n";
        registrarAtleta(atletas[i]);
    }
    Atleta mejor_atleta = encontrarMejorAtleta(atletas, 0, atletas[0]);
    cout << "\n--- Atleta con el mejor tiempo ---\n";
    cout << "Nombre: " << mejor_atleta.nombre << endl;
    cout << "País: " << mejor_atleta.pais << endl;
    return 0;
}