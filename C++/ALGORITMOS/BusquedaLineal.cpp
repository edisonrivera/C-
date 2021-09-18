#include <iostream>
using namespace std;
int lista [100];
int longitud=0;
void llenar(int &longitud, int lista[]);
void buscar(int &longitud, int lista[]);
int main (){
    llenar(longitud,lista);
    buscar(longitud,lista);
    system ("pause");
    return 0;
}

void llenar(int &longitud, int lista[]){
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    while (longitud<= 0){
    cout<<"\t\t[Solo se admiten valores mayores a 0]"<<endl;
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    }
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento: ";
        cin>>lista[i];
    }
}

void buscar(int &longitud, int lista[]){
    int numero=0;
    bool band = false;
    cout<<" > Ingrese el numero que desee buscar: ";
    cin>>numero;
    for (int i=0;i<longitud;i++){
        if (lista[i] == numero){
            cout<<"\t\t -----> N U M E R O  E N C O N T R A D O, posicion ["<<i<<"]"<<endl;
            band = true;
        }
    }
    if (band == false){
        cout<<"\t\tE L E M E N T O   N O   E N C O N T R A D O"<<endl;
    }
}
