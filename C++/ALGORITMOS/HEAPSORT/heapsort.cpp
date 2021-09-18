#include <iostream>
void heapsort (int arreglo[],int n){
    int valor, temp,a;
    for(int i = n;i>0;i--){
        for (int j =1;j<=i;j++){
            valor = arreglo[j];
            a = j/2;
            while(a>0 && arreglo[a]<valor){
                arreglo[j] = arreglo[a];
                j = a;
                a = a/2;
            }
            arreglo[j] = valor;
        }
        temp= arreglo[1];
        arreglo [1] = arreglo[i];
        arreglo[i] = temp; 
    }
}