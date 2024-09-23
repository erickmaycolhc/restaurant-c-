#pragma once
#include "Root.h"
class Producto {
public:
    int id;
    string nombre;
    float precio;
    string categoria;
    Producto* sig;

    Producto(int id, string nombre, float precio, string categoria, Producto* sig = nullptr)
        : id(id), nombre(nombre), precio(precio), categoria(categoria), sig(sig) {}

    void mostrarProducto();
};

void Producto::mostrarProducto() {
    cout << "Id: " << id << ", Categoria: " << categoria << ", Nombre: " << nombre << ", Precio: " << precio << endl;
}