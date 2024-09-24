#pragma once
#include "ListaProducto.h"
#include <string>
class Pedido {
public:
    int id;
    string cliente;
    ListaProducto* productosPedidos;
    string fecha;
    float precioTotal;
    Pedido* sig;

    Pedido(int id, string cliente, ListaProducto* productosPedidos = nullptr, string fecha = "", float precioTotal = 0, Pedido* sig = nullptr)
        : id(id), cliente(cliente), productosPedidos(productosPedidos), fecha(fecha), precioTotal(precioTotal), sig(sig) {}

    void mostrarPedido();
    void agregarProductos(int id, ListaProducto* productosLista);
};

void Pedido::mostrarPedido() {
    cout << "ID: " << id << endl;
    cout << "Cliente: " << cliente << endl;
    if (productosPedidos != nullptr) {
        productosPedidos->mostrarProducto();
    }
    cout << "Fecha: " << fecha << endl;
    cout << "Precio Total: " << precioTotal << endl;
}

void Pedido::agregarProductos(int id, ListaProducto* productosLista) {
    Producto* nuevo = productosLista->obtenerProducto(id);
    if (nuevo != nullptr) {
        productosPedidos->agregarInicial(nuevo->id, nuevo->nombre, nuevo->precio, nuevo->categoria);
        
        // Aquí sumamos el precio del nuevo producto al precio total del pedido
        precioTotal += nuevo->precio;
    }
}


