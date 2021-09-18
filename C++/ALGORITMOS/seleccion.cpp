#include <iostream>
using namespace std;

void IngresarDatos (int &longitud, int lista []);
void Ordenar (int &longitud,int lista[]);
void imprimir (int &longitud,int lista []);
int longitud = 0;
int lista [100];

int main () {
    
    IngresarDatos (longitud, lista);
    Ordenar (longitud, lista);
    imprimir ( longitud, lista);
    system ("pause");
    return 0;
}

void IngresarDatos (int &longitud, int lista []) {
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    while (longitud<= 0){
    cout<<"\t\t[Solo se admiten valores mayores a 0]"<<endl;
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    }
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}

void Ordenar (int &longitud,int lista[]){
    int max{0},min{0},aux{0},i{0},j{0};
    for ( i =0; i<longitud;i++){
        min = i;
        for ( j =i+1;j<longitud;j++){
            if (lista[j]< lista [min]){
                min = j;
            }
        }
        aux = lista[i];
        lista[i] = lista[min];
        lista [min] = aux;
    }
}

void imprimir (int &longitud,int lista []){
    for (int i = 0;i<longitud;i++){
        cout<<lista [i]<<" | ";
    }
    cout<<endl;
}