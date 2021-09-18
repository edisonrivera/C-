#include <iostream>
using namespace std;
int opcion2(int longitud);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
void interpolacion (int longitud,int lista[]);
int main(){
    int n =0;
    n = opcion2 (n);
    int arreglo [n];
    llenar(n,arreglo);
    Ordenar (n,arreglo);
    interpolacion(n, arreglo);
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
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}

void Ordenar (int longitud,int lista[]){
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
        cout<<"["<<lista[i]<<"] ";
      
    }
}

void interpolacion (int longitud, int lista[]){
    int medio = 0, num = 0, primero = 0, ultimo = 0, cont = 0;
    ultimo = longitud-1;
    cout<<endl<<" > Ingrese el numero que desee buscar: ";
    cin>>num;
    while (lista[primero] != num && cont < longitud){
        medio = primero + ((num-lista[primero])*(ultimo-primero))/(lista[ultimo] - lista[primero]);
        if (lista[medio] < num){primero = medio + 1;}
        else if (lista[medio] > num){ultimo = medio - 1;}
        else {
            primero = medio;
            cont++;
            break;
        }
    }

    if (lista[primero] != num){
        cout<<"\t ---> ELEMENTO NO ENCONTRADO"<<endl;
    }
    else {
        cout<<"\t ---> ELEMENTO ENCONTRADO"<<endl;
    }
}

// FORMULA = primero + ((num-lista[priemero])*(ultimo-primero))/(lista[ultimo]-lista[primero])