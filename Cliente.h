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

#endif // CLIENTE_H