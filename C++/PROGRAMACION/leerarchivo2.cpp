#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
int suma ();
int main (){
    cout<<fixed<<setprecision(3)<<"La suma es: "<<suma()<<endl;;
    system ("pause");
    return 0;
}
int suma(){
    float numero,suma=0;
    ifstream leerarchivo;
    leerarchivo.open("C:/Programas/C++/ALGORITMOS/datos.txt");
    if (leerarchivo.is_open()){
        leerarchivo>>numero;
        while (numero != 0){
            suma = suma + numero;
            leerarchivo>>numero;
        }
    }
    leerarchivo.close();
    return suma;
}
