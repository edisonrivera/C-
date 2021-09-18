#include <iostream>
using namespace std;
int lista(int longitud);
void llenar (int longitud, int lista[]);
void ordenar (int longitud, int lista[]);

int main(){
    int n =0, inicio = 0;
    n = lista (n);
    int *notas = NULL;
    notas = new int[n];
    llenar(n,notas);
    ordenar(n,notas);
    for (int i =0;i<n;i++){
        cout<<"["<<notas[i]<<"] ";
    }
    delete[] notas;
    cout<<endl;
    system ("pause");
    return 0;
}

int lista(int longitud){
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
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}

void ordenar (int longitud, int lista[]){
    int aux = 0;
    for (int i = 0; i<longitud;i++){
        for (int j =0;j<longitud-1;j++){
            if (lista[j] > lista[j+1]){
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
}