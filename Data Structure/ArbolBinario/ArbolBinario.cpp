#include <iostream>
using namespace std;

// Definición de la estructura de un nodo
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) {
        valor = v;
        izquierda = derecha = nullptr;
    }
};

// Clase del Árbol Binario
class ArbolBinario {
public:
    Nodo* raiz;

    ArbolBinario() {
        raiz = nullptr;
    }

    // Método para insertar un valor en el árbol
    void insertar(int valor) {
        if (raiz == nullptr) {
            raiz = new Nodo(valor);
        } else {
            insertarRecursivo(raiz, valor);
        }
    }

    // Método recursivo para insertar un valor
    void insertarRecursivo(Nodo* nodo, int valor) {
        if (valor < nodo->valor) {
            if (nodo->izquierda == nullptr) {
                nodo->izquierda = new Nodo(valor);
            } else {
                insertarRecursivo(nodo->izquierda, valor);
            }
        } else {
            if (nodo->derecha == nullptr) {
                nodo->derecha = new Nodo(valor);
            } else {
                insertarRecursivo(nodo->derecha, valor);
            }
        }
    }

    // Método para hacer un recorrido en preorden
    void recorridoPreorden() {
        recorridoPreordenRecursivo(raiz);
    }

    // Método recursivo para recorrido en preorden
    void recorridoPreordenRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return;
        cout << nodo->valor << " ";
        recorridoPreordenRecursivo(nodo->izquierda);
        recorridoPreordenRecursivo(nodo->derecha);
    }
};

int main() {
    ArbolBinario arbol;

    // Insertando valores en el árbol
    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(8);
    arbol.insertar(1);
    arbol.insertar(4);

    // Imprimir el recorrido en preorden
    cout << "Recorrido en Preorden: ";
    arbol.recorridoPreorden();
    cout << endl;

    return 0;
}
