#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
T suma(T a, T b) {
    return a + b;
}

template <typename T>
T multiplicacion(T a, T b) {
    return a * b;
}


template <typename T>
class Cuadrado { //nombre de la clase
private: T lado;	//atributo
public:	Cuadrado(T lado);	//constructor
      ~Cuadrado(); //destructor
      T Area(); //método para calcular el área del cuadrado
};

template <typename T>
Cuadrado<T>::Cuadrado(T lado) {
    this->lado = lado;
}

template<typename T>
Cuadrado<T>::~Cuadrado() {}

template<typename T>
T Cuadrado<T>::Area() {
    return lado * lado;
}

int main()
{
    double x = 10.5, y = 20.75;
    cout << "\nEntero: " << suma<double>(x, y);
    cout << "\nMultiplicaion: " << multiplicacion<double>(x, y);
    Cuadrado<double> objCuadrado(12.5);
    double resultado = objCuadrado.Area();
    cout << "\nArea: " << resultado;
    return 0;
}

