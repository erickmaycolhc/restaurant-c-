#ifndef CLIENTE_H  // Guardas de inclusi�n
#define CLIENTE_H

#include <string>
using namespace std;


class Cliente {
public:
	int id;
	string nombre;
	int edad;
	Cliente(int id, string nombre, int edad);

	//M�todos para obtener los datos del cliente
	int getId();
	string getNombre();
	int getEdad();

};


Cliente::Cliente(int id, string nombre, int edad) {
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



#endif // CLIENTE_H