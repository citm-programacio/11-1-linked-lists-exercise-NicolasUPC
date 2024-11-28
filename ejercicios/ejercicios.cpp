#include <iostream>

using namespace std;

// Nodo de la lista enlazada
struct Nodo {
    int valor;
    Nodo* siguiente;

    // Constructor
    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor de la clase
    Lista() : cabeza(nullptr) {}

    // Método para agregar un elemento al final de la lista
    void push_back(const int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (cabeza == nullptr) {
            // Si la lista está vacía, el nuevo nodo es la cabeza
            cabeza = nuevoNodo;
        }
        else {
            // Recorremos la lista hasta el final y añadimos el nuevo nodo
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    // Método para insertar un elemento en una posición específica
    void insertar(unsigned int posicion, const int valor) {
        Nodo* nuevoNodo = new Nodo(valor);

        if (posicion == 0) {
            // Insertar al inicio
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
        else {
            Nodo* actual = cabeza;
            unsigned int index = 0;

            // Recorremos la lista hasta la posición deseada o hasta el final
            while (actual != nullptr && index < posicion - 1) {
                actual = actual->siguiente;
                index++;
            }

            if (actual != nullptr) {
                nuevoNodo->siguiente = actual->siguiente;
                actual->siguiente = nuevoNodo;
            }
            else {
                // Si la posición es mayor que la longitud de la lista, agregamos al final
                push_back(valor);
            }
        }
    }

    // Método para imprimir la lista
    void imprimir() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        cout << "nullptr" << endl;
    }
};

// Función principal para probar la lista
int main() {
    Lista lista;

    // Insertar 5 elementos en diferentes posiciones e imprimir la lista después de cada inserción
    lista.push_back(10);
    lista.imprimir();  // Imprime: 10 -> nullptr

    lista.insertar(0, 5);
    lista.imprimir();  // Imprime: 5 -> 10 -> nullptr

    lista.insertar(1, 15);
    lista.imprimir();  // Imprime: 5 -> 15 -> 10 -> nullptr

    lista.insertar(2, 20);
    lista.imprimir();  // Imprime: 5 -> 15 -> 20 -> 10 -> nullptr

    lista.insertar(4, 25);
    lista.imprimir();  // Imprime: 5 -> 15 -> 20 -> 10 -> 25 -> nullptr

    lista.insertar(10, 30);
    lista.imprimir();  // Imprime: 5 -> 15 -> 20 -> 10 -> 25 -> 30 -> nullptr

    lista.insertar(5, 60);
    lista.imprimir();

    lista.insertar(9, 33);
    lista.imprimir();

    lista.insertar(8, 49);
    lista.imprimir();

    lista.insertar(11, 32);
    lista.imprimir();

    lista.insertar(6, 12);
    lista.imprimir();
    return 0;
}
