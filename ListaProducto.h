#pragma once
#include "Producto.h"
typedef unsigned int uint;

class ListaProducto {
private:
    uint lon;
public:
    Producto* ini;
    ListaProducto() : ini(nullptr), lon(0) {}
    uint longitud();
    bool esVacia();
    void agregarInicial(int id, string nombre, float precio, string categoria);
    void eliminarProducto(int id);
    Producto* obtenerProducto(int id);
    void mostrarProducto();

};

uint ListaProducto::longitud() {
    return lon;
}

bool ListaProducto::esVacia() {
    return lon == 0;
}

void ListaProducto::agregarInicial(int id, string nombre, float precio, string categoria) {
    Producto* nuevo = new Producto(id, nombre, precio, categoria, ini);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}

Producto* ListaProducto::obtenerProducto(int id) {
    Producto* aux = ini;
    while (aux != nullptr && aux->id != id) {
        aux = aux->sig;
    }
    return aux;
}

void ListaProducto::mostrarProducto() {
    Producto* actual = ini;
    while (actual != nullptr) {
        actual->mostrarProducto();
        actual = actual->sig;
    }
}

void ListaProducto::eliminarProducto(int id) {
    Producto* actual = ini;
    Producto* anterior = nullptr;

    while (actual != nullptr && actual->id != id) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual == nullptr) {
        return; // Producto no encontrado
    }

    if (anterior == nullptr) {
        ini = actual->sig; // Eliminar el primer nodo
    }
    else {
        anterior->sig = actual->sig; // Eliminar nodo en medio o al final
    }

    delete actual; // Liberar la memoria
    lon--; // Reducir la longitud
}









//float sumaPrecios(Producto* producto) {
//    if (producto == nullptr) return 0; // Caso base
//    return producto->precio + sumaPrecios(producto->sig); // Llamada recursiva
//}
//
//
//
//void mostrarProductosRecursivamente(Producto* producto) {
//    if (producto == nullptr) return; // Caso base
//    producto->mostrarProducto(); // Mostrar producto actual
//    mostrarProductosRecursivamente(producto->sig); // Llamada recursiva para el siguiente
//}
//
//
//Producto* buscarProductoPorId(Producto* producto, int id) {
//    if (producto == nullptr) return nullptr; // Caso base: no hay más productos
//    if (producto->id == id) return producto; // Producto encontrado
//    return buscarProductoPorId(producto->sig, id); // Llamada recursiva para el siguiente producto
//}



//void ordenarProductosPorPrecio(ListaProducto& listaProducto) {
//    if (listaProducto.esVacia()) return; // No hay productos para ordenar
//
//    bool intercambio;
//    do {
//        intercambio = false;
//        Producto* actual = listaProducto.ini;
//        Producto* siguiente = actual->sig;
//
//        while (siguiente != nullptr) {
//            if (actual->precio > siguiente->precio) {
//                // Intercambiar los productos
//                swap(actual->precio, siguiente->precio);
//                swap(actual->nombre, siguiente->nombre);
//                swap(actual->id, siguiente->id);
//                intercambio = true;
//            }
//            actual = siguiente;
//            siguiente = siguiente->sig;
//        }
//    } while (intercambio); // Repetir hasta que no haya más intercambios
//}



//void gestionarPlatos(ListaProducto& listaProducto) {
//    cout << "\nLista de Platos" << endl;
//    cout << "1. Ver Carta" << endl;
//    cout << "2. Modificar Precio" << endl;
//    cout << "3. Agregar Plato" << endl;
//    cout << "4. Eliminar Plato" << endl;
//    cout << "5. Ordenar Platos por Precio" << endl;
//
//    int opcion;
//    cin >> opcion;
//
//    switch (opcion) {
//    case 1:
//        listaProducto.mostrarProducto();
//        break;
//    case 2:
//        modificarPrecio(listaProducto);
//        break;
//    case 3:
//        agregarPlato(listaProducto);
//        break;
//    case 4:
//        eliminarPlato(listaProducto);
//        break;
//    case 5:
//        ordenarProductosPorPrecio(listaProducto); // Ordenar la lista
//        cout << "Productos ordenados por precio." << endl;
//        break;
//    default:
//        cout << "Opción no válida." << endl;
//    }
//} plato = 1



