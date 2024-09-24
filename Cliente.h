#ifndef CLIENTE_H  // Guardas de inclusión
#define CLIENTE_H

#include <string>
using namespace std;


class Cliente {
public:
	int id;
	string nombre;
	int edad;
	Cliente(int id, string nombre, int edad);

	//Métodos para obtener los datos del cliente
	int getId();
	string getNombre();
	int getEdad();

};


Cliente::Cliente(int id, string nombre, int edad) {
	this->id = id;
	this->nombre = nombre;
	this->edad = edad;
}

//Métodos getter

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