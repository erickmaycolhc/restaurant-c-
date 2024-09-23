#ifndef LECTORDH_H
#define LECTORDH_H

#include <vector>
#include "Cliente.h"
#include "Plato.h"

using namespace std;

class LectorDB {
public:
	vector<Cliente> leerClientes(string archivo1);
	vector<Plato> leerPlatos(string archivo2);
};



#endif // LECTORDH_H