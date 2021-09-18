#include <iostream>
using namespace std;
int contador ();
int main (){
    cout<<contador()<<endl;;
    system ("pause");
    return 0;
}

int contador(){
    char letra,cadena;
    int i=0;
    cout<<" > Ingrese la letra a buscar: ";
    cin>>letra;
    cout<<" > Ingrese la oracion terminada en punto: ";
    cin>>cadena;
    while (cadena != '.'){
        if (cadena == letra){
            i++;
        }
        cin>>cadena; //recorre de manera automática.
    }
    cout<<" - Cantidad de veces: ";
    return i;
}


