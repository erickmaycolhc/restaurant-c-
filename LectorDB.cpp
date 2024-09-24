//#include "LectorDB.h"
//#include <fstream>
//#include <sstream>
//#include <vector>
//using namespace std;
//
//string linea;
//vector<Cliente> LectorDB::leerClientes(string archivo1) {
//	vector<Cliente> clientes; //almacenar
//	ifstream archivoClientes(archivo1);
//
//	while (getline(archivoClientes, linea)) {
//		stringstream ss1(linea);
//		int id;
//		string nombre;
//		int edad;
//
//		// Leer el id, nombre y la edad
//		ss1 >> id;                // Leer el id como entero
//		ss1.ignore();  // Ignorar la coma
//		getline(ss1, nombre, ','); // Leer el nombre
//		ss1 >> edad;
//
//		//creamos un objeto Cliente y agregar al vector
//		Cliente cliente(id, nombre, edad);
//		clientes.push_back(cliente);
//	}
//	return clientes;
//}
//
//vector<Plato> LectorDB::leerPlatos(string archivo2) {
//	vector<Plato> platos;
//	ifstream archivoPlatos(archivo2);
//
//	while (getline(archivoPlatos, linea)) {
//		stringstream ss2(linea);
//		int id;
//		string nombre;
//		double precio;
//
//		ss2 >> id;
//		ss2.ignore();  // Ignorar la coma
//		getline(ss2, nombre, ',');
//		ss2 >> precio;
//
//		Plato plato(id,nombre, precio);
//		platos.push_back(plato);
//	}
//	return platos;
//}
