#include "Cliente.h"

//constructor
Cliente::Cliente(int id,  string nombre, int edad) {
	this->id = id;
	this->nombre = nombre;
	this->edad = edad;
}

//M�todos getter

int Cliente::getId() {
	return id;
}

string Cliente::getNombre() {
	return nombre;
}

int Cliente::getEdad() {
	return edad;
}
