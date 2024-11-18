// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 18/11/2024
// Número de ejercicio: 7
// Problema planteado: Inventario de productos en una tienda
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Producto 
{
    string nombre;
    string codigo;
    double precio;
    int cantidad_en_inventario;
    string observaciones;
};

void registrarProducto(Producto &producto) 
{
    cout << "Ingrese el nombre del producto: ";
    getline(cin, producto.nombre);
    cout << "Ingrese el código del producto: ";
    getline(cin, producto.codigo);
    cout << "Ingrese el precio del producto: ";
    cin >> producto.precio;
    if (producto.precio < 0) 
    {
        cin.ignore();
        cout << "Precio inválido. Intente nuevamente.\n";
        registrarProducto(producto);
        return;
    }

    cout << "Ingrese la cantidad en inventario: ";
    cin >> producto.cantidad_en_inventario;
    if (producto.cantidad_en_inventario < 0) 
    {
        cin.ignore();
        cout << "Cantidad inválida. Intente nuevamente.\n";
        registrarProducto(producto);
        return;
    }
    cin.ignore();
    if (producto.cantidad_en_inventario < 5) 
    {
        producto.observaciones = "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO";
    } else 
    {
        producto.observaciones = "SIN OBSERVACIONES";
    }
}

Producto encontrarProductoMasCaro(const vector<Producto> &productos) 
{
    Producto masCaro = productos[0];
    for (const Producto &producto : productos) 
    {
        if (producto.precio > masCaro.precio) 
        {
            masCaro = producto;
        }
    }
    return masCaro;
}

int calcularTotalProductos(const vector<Producto> &productos) 
{
    int total = 0;
    for (const Producto &producto : productos) {
        total += producto.cantidad_en_inventario;
    }
    return total;
}

int main() 
{
    int n;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    cin.ignore();
    vector<Producto> productos(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nRegistrando datos del producto " << i + 1 << ":\n";
        registrarProducto(productos[i]);
    }
    Producto masCaro = encontrarProductoMasCaro(productos);
    cout << "\n--- Producto más caro ---\n";
    cout << "Nombre: " << masCaro.nombre << endl;
    cout << "Código: " << masCaro.codigo << endl;
    cout << "Precio: $" << masCaro.precio << endl;
    cout << "Cantidad en inventario: " << masCaro.cantidad_en_inventario << endl;
    cout << "Observaciones: " << masCaro.observaciones << endl;
    int totalProductos = calcularTotalProductos(productos);
    cout << "\nCantidad total de productos en inventario: " << totalProductos << endl;
    cout << "\n--- Productos con baja cantidad de inventario ---\n";
    for (const Producto &producto : productos) 
    {
        if (producto.cantidad_en_inventario < 5) 
        {
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Cantidad en inventario: " << producto.cantidad_en_inventario << endl;
            cout << "Observaciones: " << producto.observaciones << endl;
            cout << endl;
        }
    }
    return 0;
}