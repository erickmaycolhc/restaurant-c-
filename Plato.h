#ifndef PLATO_H
#define PLATO_H

#include <string>
using namespace std;

template <typename T>   //template 1
class Plato {
public:
	int id;
	T nombre;
	double precio;

	Plato(int id, T nombre, double precio);

	int getId();
	T getNombre();
	double getPrecio();
};




template <typename T> //template 2
Plato<T>::Plato(int id, T nombre, double precio) {
	this->id = id;
	this->nombre = nombre;
	this->precio = precio;
}
 
template <typename T> //template 3
int Plato<T>::getId() {
	return id;
}

template <typename T> //template 4
T Plato<T>::getNombre() {
	return nombre;
}
template <typename T>  //template 5
double Plato<T>::getPrecio() {
	return precio;
}




#endif // PLATO_H