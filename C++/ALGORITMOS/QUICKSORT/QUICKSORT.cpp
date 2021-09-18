#include <iostream>
using namespace std;
#include "proceso.h"
int main(){
    int n =0, inicio = 0;
    n = opcion2 (n);
    int arreglo [n]; 
    llenar(n, arreglo);
    ordenar(arreglo,inicio,n-1);
    for (int i = 0;i<n;i++){
        cout<<"["<<arreglo[i]<<"] ";
    }
    system ("pause");
    return 0;
}




