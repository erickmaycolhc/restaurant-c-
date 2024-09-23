#ifndef PLATO_H
#define PLATO_H

#include <string>
using namespace std;

class Plato {
public:
	int id;
	string nombre;
	double precio;
	Plato(int id,string nombre, double precio);

	int getId();
	string getNombre();
	double getPrecio();
};

#endif // PLATO_H