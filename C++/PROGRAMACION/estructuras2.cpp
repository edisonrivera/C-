#include <iostream>
using namespace std;
typedef struct {
    string dni;
} tNif;

typedef struct {
    string nombre;
    string apellidos;
    int edad;
    tNif nif;
} tPersona;

int main (){
    tPersona persona1;
    persona1.nombre = "Edison";
    persona1.apellidos = "Rivera";
    persona1.edad = 18;
    persona1.nif.dni = "1752774305";
    cout<<"> Nombre: "<<persona1.nombre<<endl;
    cout<<"> Apellidos: "<<persona1.apellidos<<endl;
    cout<<"> Edad: "<<persona1.edad<<endl;
    cout<<"> DNI: "<<persona1.nif.dni<<endl; //acceder a dni
    system ("pause");
    return 0;
}