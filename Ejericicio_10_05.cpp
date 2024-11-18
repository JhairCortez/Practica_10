// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 5
// Problema planteado: Sistema de gestión de películas
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pelicula 
{
    string titulo;
    string director;
    int duracion;
    int anio_estreno;
    string genero;
};

void registrarPelicula(Pelicula &pelicula) 
{
    cout << "Ingrese el título de la película: ";
    getline(cin, pelicula.titulo);
    cout << "Ingrese el nombre del director: ";
    getline(cin, pelicula.director);
    cout << "Ingrese la duración de la película (en minutos): ";
    cin >> pelicula.duracion;
    if (pelicula.duracion <= 0) 
    {
        cin.ignore();
        cout << "Duración inválida. Intente nuevamente.\n";
        registrarPelicula(pelicula);
        return;
    }
    cout << "Ingrese el año de estreno: ";
    cin >> pelicula.anio_estreno;
    if (pelicula.anio_estreno <= 0) 
    {
        cin.ignore();
        cout << "Año inválido. Intente nuevamente.\n";
        registrarPelicula(pelicula);
        return;
    }
    cin.ignore();
    cout << "Ingrese el género de la película: ";
    getline(cin, pelicula.genero);
}

void mostrarPeliculasPorGenero(const vector<Pelicula> &peliculas, const string &genero) 
{
    cout << "\n--- Películas del género \"" << genero << "\" ---\n";
    bool encontrado = false;
    for (const Pelicula &pelicula : peliculas) 
    {
        if (pelicula.genero == genero) {
            encontrado = true;
            cout << "Título: " << pelicula.titulo << endl;
            cout << "Director: " << pelicula.director << endl;
            cout << "Duración: " << pelicula.duracion << " minutos" << endl;
            cout << "Año de estreno: " << pelicula.anio_estreno << endl;
            cout << endl;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron películas de este género.\n";
    }
}

void mostrarPeliculasPorDirector(const vector<Pelicula> &peliculas, const string &director) 
{
    cout << "\n--- Películas dirigidas por \"" << director << "\" ---\n";
    bool encontrado = false;
    for (const Pelicula &pelicula : peliculas) 
    {
        if (pelicula.director == director) 
        {
            encontrado = true;
            cout << "Título: " << pelicula.titulo << endl;
            cout << "Género: " << pelicula.genero << endl;
            cout << "Duración: " << pelicula.duracion << " minutos" << endl;
            cout << "Año de estreno: " << pelicula.anio_estreno << endl;
            cout << endl;
        }
    }
    if (!encontrado) 
    {
        cout << "No se encontraron películas de este director.\n";
    }
}

int main() 
{
    int n;
    cout << "Ingrese el número de películas a registrar: ";
    cin >> n;
    cin.ignore();
    vector<Pelicula> peliculas(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos de la película " << i + 1 << ":\n";
        registrarPelicula(peliculas[i]);
    }
    string criterio;
    cout << "\nIngrese un género para buscar películas: ";
    getline(cin, criterio);
    mostrarPeliculasPorGenero(peliculas, criterio);
    cout << "\nIngrese un director para buscar películas: ";
    getline(cin, criterio);
    mostrarPeliculasPorDirector(peliculas, criterio);
    return 0;
}