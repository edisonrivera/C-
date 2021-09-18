#include <iostream>
using namespace std;

int mitad (int lista[], int inicial, int longitud){
    return lista[(inicial+longitud)/2];
}

void ordenar (int lista[],int ini,int fi){
    int i = ini;
    int j = fi;
    int temp;
    int piv = mitad (lista, ini, fi);
    do{
        while (lista[i] < piv){
            i++;
        }
        while (lista[j] > piv){
            j--;
        }
        if (i <= j){
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            i++;
            j--; 
        }
    } while (i<=j);
    if (ini < j){
        ordenar (lista,ini,j);
    }
    if (i < fi){
        ordenar(lista,i,fi);
    }
}

void llenar (int longitud, int lista[]){
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
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

