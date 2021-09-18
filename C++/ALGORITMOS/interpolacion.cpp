#include <iostream>
using namespace std;
#include <fstream>
const int MAX = 100;
int X;
int arreglo[MAX];
int interpolacion (int arreglo[], int &numero, int X);
void mostrarArreglo (int arreglo [], int numero);
void insercion (int arreglo [], int numero);
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
        leer<<arreglo[i]<<" ";

    }
    cout << endl;
    leer<<endl;
    mostrarArreglo (arreglo, numero);
    insercion (arreglo, numero);
    resultado = interpolacion (arreglo, numero, X);
    if (resultado == -1) {
        leer<<"NO ENCONTRADO POSICION"<<endl;
        cout << "> Elemento no encontrado";
    }
    else { 
        cout << "> Elemento encontrado" << "\t --Posicion: << " << resultado;
        leer<<"ENCONTRADO POSICION ["<<resultado<<"]"<<endl;
        
    }
    cout << endl;
    leer.close();
    system ("pause");
    return 0;
}

void mostrarArreglo (int arreglo [], int numero) {
    cout << "> V E C T O R  S I N  O R D E N A R" << endl;
    for (int i = 0; i < numero; i++) {
        cout << "[" << arreglo[i] << "]";
    }
}

int interpolacion (int arreglo[], int &numero, int X) {
    ofstream leer;
    leer.open("C:/Programas/C++/ALGORITMOS/BDD/interpolacion.txt", ios::out | ios:: app);
    int primero = 0;
    int ultimo = numero-1;
    int medio;
    cout << endl;
    cout << "> Ingrese el elemento a encontrar: ";
    cin >> X;
    leer<<X<<endl;

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

void insercion (int arreglo [], int numero) {
    int pos = 0,aux = 0;
    ofstream leer;
    leer.open("C:/Programas/C++/ALGORITMOS/BDD/interpolacion.txt", ios::out | ios:: app);
    for (int i =0; i < numero ;i++){
        pos = i;
        aux = arreglo[i];
        while ((pos>0) && (arreglo [pos-1] > aux)){
            arreglo [pos] = arreglo [pos-1];
            pos--;
        }
        arreglo [pos] = aux;
    }
    cout << endl;
    cout<<"> V E C T O R   O R D E N A D O"<<endl;
    for (int i =0;i < numero;i++){
        cout<<"["<< arreglo[i]<<"] ";
        leer<<arreglo[i]<<" ";
    }
    leer<<endl;
    leer.close();
}