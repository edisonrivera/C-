#include <iostream>
#include "calculos.h"
using namespace std;
#include <unistd.h>
#include <iomanip>
#include <cmath>

int menu();
int main (){
    int opcion = 0;
    while (opcion!=8){
        opcion = menu();
        switch (opcion){
        case 1:
            sumar();
        break;
        case 2:
            restar();
        break;
        case 3:
            multiplicacion();
        break;
        case 4:
            division();
        break;
        case 5:
            potenciacion();
        break;
        case 6:
            raiz ();
        break;
        case 7:
            factorial();
        break;
        case 8:
            exit(8);
        break;
        default:
        break;
        }
    }
    system ("pause");
    return 0;
}

int menu(){
    int op = 0;
    while (op<1 || op>8){
        cout<<setw(70)<<"___________________________"<<endl;
        cout<<setw(70)<<"|    MENU DE OPCIONES      |"<<endl;
        cout<<setw(70)<<"|                          |"<<endl;
        cout<<setw(70)<<"|1.- SUMA                  |"<<endl;
        cout<<setw(70)<<"|2.- RESTA                 |"<<endl;
        cout<<setw(70)<<"|3.- MULTIPLICACION        |"<<endl;
        cout<<setw(70)<<"|4.- DIVISION              |"<<endl;
        cout<<setw(70)<<"|5.- POTENCIACION          |"<<endl;
        cout<<setw(70)<<"|6.- RAIZ CUADRADA         |"<<endl;
        cout<<setw(70)<<"|7.- FACTORIAL             |"<<endl;
        cout<<setw(70)<<"|8.- SALIR                 |"<<endl;
        cout<<setw(70)<<"|__________________________|"<<endl;
        cout<<"\n"<<setw(63)<<" > INGRESE SU OPCION: ";
        cin>>op;
        if (op<1 || op>8){
            cout<<setw(69)<<"- LA OPCION NO ES VALIDA -";
            sleep(2);
            system ("cls");
        }
    }
    system ("cls");
    return op;
}