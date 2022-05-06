#ifndef estructurass_h
#define estructurass_h
#include <string>
using namespace std;
const int MAX = 100;
typedef struct{
    string nombre_completo;
    string cedula;
    int edad;
    string especialidad;
    int dia;
    int mes;
    int year;
}tFormulario;

typedef struct{
    int cont;
    tFormulario datos[MAX]; 
}tLista;

typedef struct {
    string nombre;
    string apellido;
    string nif;
    string titulo;
}tDoctor;

typedef struct{
    int cont2;
    tDoctor datosDoctor[MAX];
}tLista2;
#endif