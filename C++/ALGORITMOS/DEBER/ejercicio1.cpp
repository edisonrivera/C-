#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

void llenarArreglo (int longitud, int numero[]){
    for (int i = 0;i < longitud; i++){
        int numeros = rand () % 15 + 66;
        numero[i] = numeros;
    }
}

void guardar1 (int longitud, int numero[]){
    ofstream arreglo;   
    arreglo.open ("Ejercicio1.txt",ios::out);
    arreglo << "ELEMENTOS" << endl;
    for (int i = 0; i < longitud; i++){
         arreglo<<"["<<numero[i]<<"] ";
    }
    arreglo << endl;
    arreglo.close();
}

void mostrarElementos (int longitud, int const numero[]){
    for (int i = 0; i < longitud; i++){
        cout << "[" << numero[i] << "]";
    }
}

void mayor (int longitud, int numero[]){
    ofstream arreglo;
    arreglo.open ("Ejercicio1.txt",ios::out| ios::app);
    int max = 0;
     max = numero[0];
    for (int i = 0; i < longitud; i ++){
        if(numero[i]>max){
            max = numero[i];
        }
    }
    cout << "\nEL NUMERO MAYOR ES: " << max;
    arreglo << "EL NUMERO MAYOR ES: " << max;
    arreglo << endl;
    arreglo.close();
}

void menor (int longitud, int numero[]){
    ofstream arreglo;
    arreglo.open ("Ejercicio1.txt",ios::out| ios::app);
    int min = 0;
    min = numero[0];
    for (int i = 0; i < longitud; i ++){
        if(numero[i]<min){
            min = numero[i];
        }
    }
    cout << "\nEL NUMERO MENOR ES: " << min;
    arreglo << "EL NUMERO MENOR ES: " << min;
    arreglo << endl;
    cout<<endl;
    arreglo.close();
}

void repetidos(int longitud, int numero[]){
    ofstream arreglo;
    int cont;
    arreglo.open ("Ejercicio1.txt",ios::out| ios::app);
    int veces = 0;
    for (int i = 0;i<longitud;i++){    
        for (int j = i+1;j<longitud;j++){
            if (numero[i] == numero[j]){
                veces++;
                cout<<"El numero ["<<numero[i]<<"] esta repetido: "<<veces<<endl;
                arreglo<<"El numero ["<<numero[i]<<"] esta repetido: "<<veces<<endl;
                veces = 0;
            }
        }
    }
    arreglo << endl;
    cout<<endl;
    arreglo.close();
}
