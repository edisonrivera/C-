#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "ejercicio1.h"
#include "ejercicio2.h"
#include "ejercicio3.h"

ofstream archivo;
#define tam 50
int const Max = 100;
int menuPrincipal ();
int main () {
    int opcion;
    do {
        opcion = menuPrincipal();
        switch (opcion){
            case 1: {
                    int tamanio = 0;
                    int numero [Max] = {0};
                    cout << "\t\tEJERCICIO" << endl;
                    cout << "> Ingrese el tamanio del arreglo: ";
                    cin >> tamanio;
                    srand(time(0));
                    llenarArreglo (tamanio, numero);
                    guardar1 (tamanio, numero);
                    mostrarElementos (tamanio, numero);
                    mayor (tamanio,numero);
                    menor (tamanio,numero);
                    repetidos(tamanio, numero);
            }
            break;
            case 2: {
                    double arreglo1[tam];
                    archivo.open("ejercicio2.txt",ios::out);
                    archivo<<"\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl<<endl;
                    int n;
                    int op = menu();
                    while (op != 5){
                        switch (op)
                        {
                            case 1:{
                                    cout<<"Ingresa el numero de transacciones: ";
                                    cin>>n;
                                    ingresar(arreglo1,n);
                                    archivo<<"Transacciones: ";
                                    guardar(arreglo1, n);
                                    break;
                                }
                            case 2:{
                                    imprimir(arreglo1, n);
                                    guardar(arreglo1, n);
                                    break;
                                } 
                            case 3:{
                                system("cls");
                                cout<<"\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl; 
                                dividir(arreglo1,0,n-1);
                                imprimir(arreglo1, n);
                                archivo.open("ejercicio2.txt",ios::out | ios::app);
                                archivo<<"Transacciones ordenadas: ";
                                archivo.close();
                                guardar(arreglo1, n);
                                    break;
                                } 
                            case 4:{
                                    system("cls");
                                    buscar(n, arreglo1);
                                    break;
                                }
                        }
                        op = menu();
                    }
            }
            break;
            case 3: {
                titulo();
                sucursal();
                ingresar();
            }
            break;
            case 0:
            break;
        }
    } while (opcion != 0);
    system ("pause");
    return 0;
}

int menuPrincipal () {
    int opcion = -1;
    while (opcion < 0 || opcion > 3){
        cout << "\t\t ---> M E N U  P R I N C I P A L <--- \t\t" << endl;
        cout<< "> 1. EJERCICIO 1"<<endl; 
        cout<< "> 2. EJERCICIO 2"<<endl;
        cout<< "> 3. EJERCICIO 3"<<endl;
        cout<< "> 0. SALIR"<<endl;
        cout<<"\tIngrese su opcion: ";
        cin>> opcion;
        if ((opcion < 0 || opcion > 3)){
            cout << "> Opcion no valida" << endl;
        }
    }
    return opcion;
}

