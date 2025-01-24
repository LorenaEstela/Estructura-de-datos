#include <iostream>
#include <string>

using namespace std;

// Función de hash simple
unsigned int hash_simple(const string& input) {
    unsigned int hash = 0;

    for (char c : input) {
        hash = (hash * 31) + c;  // Operación común en funciones hash
    }

    return hash;
}

int main() {
    string input;
    cout << "Introduce el texto a hashear: ";
    getline(cin, input);

    // Generar el hash
    unsigned int resultado_hash = hash_simple(input);

    // Mostrar el resultado
    cout << "El hash simple es: " << resultado_hash << endl;
  
    return 0;
}
