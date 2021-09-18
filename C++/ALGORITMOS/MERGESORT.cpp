#include <iostream>
using namespace std;
#include <fstream>
int opcion2(int longitud);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
void dividir (int lista[], int inicial, int longitud);
void fusionar (int lista[],int ini,int fi,int medio);
int main(){
    ofstream llenarx;
    int n =0, inicio = 0;
    n = opcion2 (n);
    int arreglo [n];
    llenar(n, arreglo);
    dividir(arreglo,inicio,n-1);
    llenarx.open("C:/Programas/C++/ALGORITMOS/BDD/mergesort.txt", ios::out | ios::app);
    for (int i =0;i<n;i++){
        cout<<"["<<arreglo[i]<<"] ";
        llenarx<<"["<<arreglo[i]<<"] ";
    }
    llenarx<<endl;
    cout<<endl;
    llenarx.close();
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
    ofstream llenarx;
    llenarx.open ("C:/Programas/C++/ALGORITMOS/BDD/mergesort.txt",ios::out | ios::app);
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
        llenarx<<"["<<lista[i]<<"] ";
    }
    llenarx<<endl;
    llenarx.close();
}

void dividir (int lista[], int inicial, int longitud){
    int mitad;
    if (inicial < longitud){
        mitad = (longitud+inicial)/2;
        dividir (lista,inicial,mitad);
        dividir (lista,mitad+1,longitud);
        fusionar(lista,inicial,longitud,mitad);
    }
}

void fusionar (int lista[], int ini,int fi,int medio){
    int i,j,k,temp[fi-ini+1];
    k = 0;
    i = ini;
    j = medio +1;
    while(i<=medio && j <=fi){
        if (lista[i] < lista[j]){
            temp [k] =  lista[i];
            k++;
            i++;
        }
        else{
            temp [k] = lista[j];
            k++;
            j++;
        }
    }    
    while (i<=medio){
        temp[k] = lista[i];
        i++;
        k++;
    }
    while (j<=fi){
        temp [k] = lista[j];
        k++;
        j++;
    }
    for (i=ini;i<=fi;i++){
        lista[i] = temp[i-ini];
    }
}