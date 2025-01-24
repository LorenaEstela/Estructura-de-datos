#include <iostream>
using namespace std;

// Tamaño del Sudoku
#define N 9

// Función para verificar si es seguro colocar un número en la posición (row, col)
bool esSeguro(int sudoku[N][N], int row, int col, int num) {
    // Comprobar si el número ya está en la fila
    for (int x = 0; x < N; x++) {
        if (sudoku[row][x] == num) {
            return false;
        }
    }

    // Comprobar si el número ya está en la columna
    for (int x = 0; x < N; x++) {
        if (sudoku[x][col] == num) {
            return false;
        }
    }

    // Comprobar si el número está en el subcuadro 3x3
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Función de retroceso para resolver el Sudoku
bool resolverSudoku(int sudoku[N][N]) {
    int row, col;
    bool vacio = false;

    // Buscar una celda vacía
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                vacio = true;
                break;
            }
        }
        if (vacio) break;
    }

    // Si no se encontró ninguna celda vacía, el Sudoku está resuelto
    if (!vacio) {
        return true;
    }

    // Intentar colocar los números del 1 al 9 en la celda vacía
    for (int num = 1; num <= N; num++) {
        if (esSeguro(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            // Llamada recursiva para resolver el Sudoku
            if (resolverSudoku(sudoku)) {
                return true;
            }

            // Si no funciona, deshacer el cambio (backtrack)
            sudoku[row][col] = 0;
        }
    }

    return false;  // Si no se pudo colocar ningún número
}

// Función para imprimir el Sudoku
void imprimirSudoku(int sudoku[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << sudoku[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sudoku a resolver (0 representa una celda vacía)
    int sudoku[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (resolverSudoku(sudoku)) {
        cout << "Sudoku resuelto: " << endl;
        imprimirSudoku(sudoku);
    } else {
        cout << "No se pudo resolver el Sudoku." << endl;
    }
    return 0;
}
