#include <iostream>
using namespace std;
int calcular ();
int main(){
    cout<<"> El resultado es: "<<calcular()<<endl;
    system ("pause");
    return 0;
}
int calcular (){
    int numeros []= {1,1,2,3,4,5,5,5,6};
    int longitud = 0,suma = 0,aux=0,mayor = 0,aux2 = 0,i=0;
    longitud = (sizeof(numeros)/sizeof(numeros[0]));
    for (int i =0;i<longitud;i++){ 
        for (int j=0;j<longitud-1;j++){
            if (numeros[j]>numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
    int sumas [longitud];
    for (int i = 0; i<longitud;i++){
        suma = 0;
        for (int j =0; j<longitud;j++){
            if (numeros[j] != numeros[i]){
                suma += numeros[j];
            }
        }
        mayor  = suma;
        sumas [i] = mayor;
    }
    aux2 = sumas[0];
    bool band = false;
    int j = 0;
    while (band == false && i<longitud){
        i++;
        if ((sumas[i] >= aux2) && (numeros[j] != numeros[i])){
            aux2 = sumas[i];
            band = true;
        } 
    }
    return i;
}
