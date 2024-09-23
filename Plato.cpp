#include "Plato.h"

// Constructor
Plato::Plato(int id, string nombre, double precio) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
}

int Plato::getId() {
    return id;
}

string Plato::getNombre() {
    return nombre;
}

double Plato::getPrecio() {
    return precio;
}
