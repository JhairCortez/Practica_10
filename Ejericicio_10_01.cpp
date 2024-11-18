// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 1
// Problema planteado: Registro de una biblioteca
#include <iostream>
#include <string>
using namespace std;

struct Libro 
{
    string titulo;             
    string autor;              
    int anio_publicacion;      
    bool disponible;           
};

void registrarLibro(Libro &libro) 
{
    cout << "Ingrese el título del libro: ";
    getline(cin, libro.titulo);
    cout << "Ingrese el autor del libro: ";
    getline(cin, libro.autor);

    cout << "Ingrese el año de publicación del libro: ";
    cin >> libro.anio_publicacion;

    if (libro.anio_publicacion < 0) 
    {
        cin.ignore();
        cout << "Año inválido, por favor intente nuevamente.\n";
        registrarLibro(libro); 
        return;
    }

    cout << "¿El libro está disponible? (1 para Sí, 0 para No): ";
    cin >> libro.disponible;

    if (libro.disponible != 0 && libro.disponible != 1) 
    {
        cin.ignore();
        cout << "Valor inválido, por favor intente nuevamente.\n";
        registrarLibro(libro); 
        return;
    }

    cin.ignore(); 
}

void mostrarLibro(const Libro &libro) 
{
    cout << "\n--- Datos del Libro ---\n";
    cout << "Título: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Año de Publicación: " << libro.anio_publicacion << endl;
    cout << "Disponibilidad: " << (libro.disponible ? "Disponible" : "No disponible") << endl;
}

int main() 
{
    Libro libro; 
    registrarLibro(libro); 
    mostrarLibro(libro);   
    return 0;
}
