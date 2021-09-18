#include <iostream>
using namespace std;
#include <array> // Plantillas para arrays
#include <algorithm> // sort y binary_search
int main (){
    const int LONGITUD = 5;
    int num=0;
    array <int,LONGITUD>arreglo;
    for (size_t i = 0;i<arreglo.size();i++){
        cout<<" > Ingrese los elementos del <array>, Posicion ["<<i<<"]: ";
        cin>>arreglo[i];
    }
    for (size_t j = 0;j<arreglo.size();j++){    //size_t (Se usa como contador en arrays)
        cout<<"Posicion ["<<j<<"]: "<<arreglo[j]<<endl;
    }
    sort (arreglo.begin(), arreglo.end());
    cout<<"-Usando un \"for range\": ";
    for (int i: arreglo){ // (int i) iterador   (arreglo) A través del cual va a iterar
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    cout<<" > Que valor desea buscar: ";
    cin>>num;
    
    bool encontrar = binary_search(arreglo.begin(),arreglo.end(),num);
    cout<<"> El numero ["<<num<<"] "<<(encontrar ? "se":"no se")<<" encuentra en el array"<<endl;  
    system ("pause");
    return 0;
}