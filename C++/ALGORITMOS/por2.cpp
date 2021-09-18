#include <iostream>
using namespace std;
int opcion2(int longitud);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
int main (){  
    int n =0;
    n = opcion2 (n);
    int arreglo [n];
    llenar (n,arreglo);
    Ordenar (n,arreglo);
    system ("pause");
    return 0;
}


int opcion2(int longitud){
    cout<<" > INGRESE LA LONGITUD DE LA LISTA: ";
    cin>>longitud;
    while (longitud<=0){
        cout<<"\t\t [INGRESE UNA LONGITUD MAYOR A 0]"<<endl;
        cout<<" > INGRESE LA LONGITUD DE LA LISTA: ";
        cin>>longitud;
    }
    return longitud;
}

void Ordenar (int longitud,int lista[]){
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
    cout<<"\t\tL I S T A   O R D E N A D A"<<endl;
    for (int i =0;i<longitud;i++){
        cout<<"["<<lista[i]<<"] ";
    }
    cout<<endl;
}

void llenar (int longitud, int lista[]){
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}