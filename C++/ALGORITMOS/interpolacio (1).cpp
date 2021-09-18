#include <iostream>
using namespace std;
#include <fstream>
const int MAX = 100;
int X;
int arreglo[MAX];
int interpolacion (int arreglo[], int &numero, int X);
void mostrarArreglo (int arreglo [], int numero);
int main()
{
    ofstream leer;
    leer.open("C:/Programas/C++/ALGORITMOS/BDD/interpolacion.txt", ios::out | ios:: app);
    int resultado = 0;
    int numero;
    cout << "> Ingrese la longitud del arreglo: ";
    cin >> numero;
    while (numero < 0) {
        cout << "> Ingrese longitud mayor a 0" << endl;
        cout << "> Ingrese la longitud del arreglo: ";
        cin >> numero;
    }
    for (int i = 0; i < numero; i++) {
        cout << "> Elemento N" << i+1 << " :";
        cin >> arreglo [i];
        leer<<arreglo[i];

    }
    leer<<endl;
    cout << endl;
    mostrarArreglo (arreglo, numero);
    resultado = interpolacion (arreglo, numero, X);
    if (resultado == -1) {
        cout << "> Elemento no encontrado";
    }
    else { 
        cout << "> Elemento encontrado" << "\t --Posicion: << " << resultado;
    }
    cout << endl;
    system ("pause");
    return 0;
}

void mostrarArreglo (int arreglo [], int numero) {
    for (int i = 0; i < numero; i++) {
        cout << "[" << arreglo[i] << "]";
    }
}

int interpolacion (int arreglo[], int &numero, int X) {
    int primero = 0;
    int ultimo = numero-1;
    int medio;
    cout << endl;
    cout << "> Ingrese el elemento a encontrar: ";
    cin >> X;
    while ((arreglo[primero] != arreglo[ultimo]) && (X >= arreglo[primero]) && (X <= arreglo[ultimo])) {
        medio = primero + ((X - arreglo[primero]) * (ultimo - primero) / (arreglo[ultimo] - arreglo[primero]));
        if (arreglo [medio] < X) {
            ultimo = medio + 1;
        }
        else if (X < arreglo [medio]) {
            ultimo = medio - 1;
        }
        else {
            return medio;
        }
    }

    if (X == arreglo [primero]) {
        return primero;
    }
    else {
        return -1;
    }
}