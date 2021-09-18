#include <iostream>
using namespace std;
#include <fstream>
int opcion2(int longitud);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
int main(){
    int n =0;
    n = opcion2 (n);
    int arreglo [n];
    llenar(n,arreglo);
    Ordenar (n,arreglo);
    cout<<endl;
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

void llenar (int longitud, int lista[]){
    ofstream ingresar;
    ingresar.open("C:/Programas/C++/ALGORITMOS/BDD/insercion.txt", ios::out | ios::app);
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
        ingresar<<lista[i]<<" ";
    }
    ingresar<<endl;
    ingresar.close();
}

void Ordenar (int longitud,int lista[]){
    ofstream ingresar;
    ingresar.open("C:/Programas/C++/ALGORITMOS/BDD/insercion.txt",ios::out | ios::app);
    int pos = 0,aux = 0;
    for (int i =0; i<longitud;i++){
        pos = i;
        aux = lista[i];
        while ((pos>0) && (lista[pos-1] > aux)){
            lista[pos] = lista[pos-1];
            pos--;
        }
        lista[pos] = aux;
    }
    cout<<"\t\tV E C T O R   O R D E N A D O"<<endl;
    for (int i =0;i<longitud;i++){
        ingresar<<lista[i]<<" ";
        cout<<"["<<lista[i]<<"] ";
    }
    ingresar<<endl;
    ingresar.close();
}