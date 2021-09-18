#include <iostream>
using namespace std;
void ingresar_elementos(int a[],int n);
void ordenar_elementos (int a[],int n);
void mostrar_elementos (int a[],int n);

int main (){
    int tam = 50,arreglo[tam],n=0;
    cout<<" > Ingrese al cantidad de elementos de su arreglo: ";
    cin>>n;
    ingresar_elementos (arreglo,n);
    ordenar_elementos (arreglo,n);
    mostrar_elementos (arreglo,n);
    system("pause");
    return 0;
}

void ingresar_elementos(int a[],int n){
    int i = 0;
    for (i;i<n;i++){
        cout<<" > Posicion ["<<i+1<<"] Ingrese el elemento: ";
        cin>>a[i];
    }
}
void ordenar_elementos (int a[],int n){
    int aux=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1;j++){
            if (a[j]>a[j+1]){
                aux = a[j];
                a[j]= a[j+1];
                a[j+1]=aux;
            }
        }
    }
}
void mostrar_elementos(int a[],int n){
    for (int i=0;i<n;i++){
        cout<<"["<<a[i]<<"] ";
    }
}