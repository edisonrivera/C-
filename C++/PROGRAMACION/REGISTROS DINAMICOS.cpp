#include <iostream>
using namespace std;
typedef struct{
    string nombre;
    int edad;
}tDatos;

tDatos nuevo();

int main (){
    tDatos reg;
    reg = nuevo();
    tDatos *puntero = new tDatos (reg);
    cout<<"NOMBRE: "<<puntero->nombre;
    cout<<"EDAD: "<<puntero->edad;
    delete puntero;
    system ("pause");
    return 0; 
}

tDatos nuevo(){
    tDatos reg;
    cout<<"NOMBRE: ";
    getline(cin,reg.nombre);
    cout<<"EDAD: ";
    cin>>reg.edad;
    return reg;
}