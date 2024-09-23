#include <iostream>
#include <string>
#include <vector>
#include "LectorDB.h"
#include "ListaProducto.h"
#include "Pedido.h"
using namespace std;

void mostrarMenu();
void registrarPedido(LectorDB& lector, ListaProducto& listaProducto, vector<Pedido>& pedidos);
void gestionarPlatos(ListaProducto& listaProducto);
void generarInformes(vector<Pedido>& pedidos, LectorDB& lector);
void modificarPrecio(ListaProducto& listaProducto);
void agregarPlato(ListaProducto& listaProducto);
void eliminarPlato(ListaProducto& listaProducto);
void verHistorialPedidos(vector<Pedido>& pedidos);
void verPlatosDemandados();
void verHistorialClientes(LectorDB& lector);

int main() {
    LectorDB lector;
    ListaProducto listaProducto;
    vector<Pedido> pedidos;

    // Leer datos iniciales desde los archivos
    vector<Cliente> clientes = lector.leerClientes("dbClientes.txt");
    vector<Plato> platos = lector.leerPlatos("dbPlatos.txt");

    for (Plato plato : platos) {
        listaProducto.agregarInicial(plato.getId(), plato.getNombre(), plato.getPrecio(), "Comida");
    }

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            registrarPedido(lector, listaProducto, pedidos);
            break;
        case 2:
            gestionarPlatos(listaProducto);
            break;
        case 3:
            generarInformes(pedidos, lector);
            break;
        case 4:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 4);

    return 0;
}

void mostrarMenu() {
    cout << "\nRestaurante Pepito" << endl;
    cout << "1. Registrar Pedido" << endl;
    cout << "2. Lista de Platos" << endl;
    cout << "3. Generar Informes" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opción: ";
}

void registrarPedido(LectorDB& lector, ListaProducto& listaProducto, vector<Pedido>& pedidos) {
    cout << "\nRegistrar Pedido" << endl;

    string nombreCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombreCliente);

    Pedido nuevoPedido(pedidos.size() + 1, nombreCliente, new ListaProducto());

    char continuar;
    do {
        int idPlato;
        listaProducto.mostrarProducto();
        cout << "Seleccionar Plato (ID): ";
        cin >> idPlato;

        nuevoPedido.agregarProductos(idPlato, &listaProducto);

        cout << "¿Desea agregar otro plato? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << "Fecha del pedido (dd/mm/aaaa): ";
    string fecha;
    cin >> fecha;
    nuevoPedido.fecha = fecha;

    // Calcular precio total
    // Calcular precio total
float total = 0;

// Recorremos la lista de productos en el pedido
Producto* actual = nuevoPedido.productosPedidos->ini; // Usar el puntero al inicio de la lista

while (actual != nullptr) {
    total += actual->precio; // Sumamos el precio de cada producto
    actual = actual->sig;    // Pasamos al siguiente producto
}

// Asignamos el total al pedido
nuevoPedido.precioTotal = total;

cout << "Total a Pagar: " << total << endl;
cout << "Método de Pago (Efectivo/Tarjeta): ";
string metodoPago;
cin >> metodoPago;

cout << "Pedido registrado correctamente!" << endl;
pedidos.push_back(nuevoPedido);
}

void gestionarPlatos(ListaProducto& listaProducto) {
    cout << "\nLista de Platos" << endl;
    cout << "1. Ver Carta" << endl;
    cout << "2. Modificar Precio" << endl;
    cout << "3. Agregar Plato" << endl;
    cout << "4. Eliminar Plato" << endl;

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
        listaProducto.mostrarProducto();
        break;
    case 2:
        modificarPrecio(listaProducto);
        break;
    case 3:
        agregarPlato(listaProducto);
        break;
    case 4:
        eliminarPlato(listaProducto);
        break;
    default:
        cout << "Opción no válida." << endl;
    }
}

void modificarPrecio(ListaProducto& listaProducto) {
    cout << "Modificar Precio" << endl;
    int id;
    float nuevoPrecio;
    cout << "ID del Plato: ";
    cin >> id;
    cout << "Nuevo Precio: ";
    cin >> nuevoPrecio;

    Producto* producto = listaProducto.obtenerProducto(id);
    if (producto != nullptr) {
        producto->precio = nuevoPrecio;
        cout << "Precio modificado correctamente." << endl;
    }
    else {
        cout << "Plato no encontrado." << endl;
    }
}

void agregarPlato(ListaProducto& listaProducto) {
    cout << "Agregar Plato" << endl;
    int id;
    string nombre;
    float precio;
    string categoria;

    cout << "ID del Plato: ";
    cin >> id;
    cout << "Nombre del Plato: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Precio: ";
    cin >> precio;
    cout << "Categoría: ";
    cin >> categoria;

    listaProducto.agregarInicial(id, nombre, precio, categoria);
    cout << "Plato agregado correctamente." << endl;
}

void eliminarPlato(ListaProducto& listaProducto) {
    cout << "Eliminar Plato" << endl;
    int id;
    cout << "ID del Plato: ";
    cin >> id;

    listaProducto.eliminarProducto(id);
    cout << "Plato eliminado correctamente." << endl;
}

void generarInformes(vector<Pedido>& pedidos, LectorDB& lector) {
    cout << "\nGenerar Informes" << endl;
    cout << "1. Historial de Pedidos" << endl;
    cout << "2. Platos Más Demandados" << endl;
    cout << "3. Historial de Clientes" << endl;

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
        verHistorialPedidos(pedidos);
        break;
    case 2:
        verPlatosDemandados();
        break;
    case 3:
        verHistorialClientes(lector);
        break;
    default:
        cout << "Opción no válida." << endl;
    }
}

void verHistorialPedidos(vector<Pedido>& pedidos) {
    cout << "\nHistorial de Pedidos" << endl;
    if (pedidos.empty()) {
        cout << "No hay pedidos registrados." << endl;
        return;
    }
    for (Pedido& pedido : pedidos) {
        pedido.mostrarPedido();
    }
}

void verPlatosDemandados() {
    cout << "\nPlatos Más Demandados" << endl;
    cout << "1. Pollo a la Brasa" << endl;
    cout << "2. Arroz con Pollo" << endl;
    cout << "3. Broaster" << endl;
}

void verHistorialClientes(LectorDB& lector) {
    cout << "\nHistorial de Clientes" << endl;
    vector<Cliente> clientes = lector.leerClientes("dbClientes.txt");
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    for (Cliente cliente : clientes) {
        cout << "ID: " << cliente.getId() << ", Nombre: " << cliente.getNombre() << ", Edad: " << cliente.getEdad() << endl;
    }
}



