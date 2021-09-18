#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <fstream>
const int MAX = 100;
typedef struct {
    int num;
    string titulo;
    string autor;
    string genero;
}tCancion;

typedef struct {
    tCancion datos[MAX];
    int contador;
}tLista;

int menu ();
void cargar(tLista &lista, bool &ok);
void guardar (const tLista &lista);
void leerEstudiante(tEstudiante &estudiante);
void insertarEstudiante(tLista &lista, tEstudiante estudiante, bool &ok);
void eliminarEstudiante(tLista &lista, int pos, bool &ok);
string nombreCompleto(tEstudiante estudiante);

void mostrarEstudiante(tEstudiante estudiante);
void listado(const tLista &lista, double media, int mayor);
int main (){
    tLista lista;
    tEstudiante estudiante;
    bool exito;
    int opcion = 0,pos;
    cargar(lista,exito);
    if (!exito){
        cout<<setw(35)<<"[E R R O R]"<<endl;
    }
    else {
        do { // El bucle do evita tener que leer antes la primera opción
            opcion = menu();
            switch (opcion) {
                case 1:{
                    leerEstudiante(estudiante);
                    insertarEstudiante(lista, estudiante, exito);
                    if (!exito) {
                        cout << "Lista llena: imposible insertar" << endl;
                    }
                }
                break;
                case 2:{
                    cout << "Posición: ";
                    cin >> pos;
                    eliminarEstudiante(lista, pos - 1, exito);
                    if (!exito) {
                        cout << "Elemento inexistente!" << endl;
                    }
                }
                break;
                case 3:{
                    calificar(lista);
                }
                break;
                case 4:{
                    listado(lista, mediaClase(lista), mayorNota(lista));
                }
            }
        } while (opcion != 0);
        guardar(lista);
    }
    system ("pause");
    return 0;
}

int menu (){
    int op=0;
    cout<<"1.- ANIADIR"<<endl;
    cout<<"2.- ELIMINAR"<<endl;
    cout<<"3.- CALIFICAR"<<endl;
    cout<<"4.- LISTADO"<<endl;
    cout<<"0.- SALIR"<<endl;
    cout<<" > Ingrese su opcion: ";
    cin>>op;
    while (op<0 || op>4){
        cout<<setw(35)<<"[OPCION NO VALIDA]"<<endl;
        cout<<" > Ingrese su opcion: ";
        cin>>op;
    }
    return op;
}

void cargar(tLista &lista, bool &ok){
    tEstudiante estudiante;
    ifstream archivo;
    char aux;
    lista.contador = 0;
    archivo.open ("clase.txt");
    if (!archivo.is_open()){
        ok = false;
        cout<<setw(35)<<"[NO SE LOGRO ABRIR]"<<endl;
    }
    else{
        ok = true;
        getline (archivo, estudiante.nombre);
        while ((estudiante.nombre != "XXX") && (lista.contador<MAX)){
            getline(archivo,estudiante.apellidos);
            archivo>>estudiante.edad;
            archivo>>estudiante.nif;
            archivo>>estudiante.nota;
            archivo.get(aux);
            lista.elementos[lista.contador] = estudiante;
            lista.contador ++;
            getline (archivo,estudiante.nombre); //pasa al siguiente nombre
        }
        archivo.close();
    }
}

void leerEstudiante(tEstudiante &estudiante){
    cin.sync();
    cout<<"> Nombre: ";
    getline(cin,estudiante.nombre);
    cout<<"> Apellidos: ";
    getline(cin,estudiante.apellidos);
    cout<<"> Edad: ";
    cin>>estudiante.edad;
    cout<<"> NIF: ";
    cin>>estudiante.nif;
    estudiante.nota = -1;
    cin.sync();
}

void insertarEstudiante(tLista &lista,tEstudiante estudiante, bool &ok){
    ok = true;
    if (lista.contador == MAX){
        ok = false;
    }
    else {
        lista.elementos[lista.contador] = estudiante;
        lista.contador++;
    }
}

void eliminarEstudiante(tLista &lista, int pos, bool &ok) {
// Espera el índice del elemento en pos
    if ((pos < 0) || (pos > lista.contador - 1)) {
        ok = false; // Elemento inexistente
    }
    else {
        ok = true;
        for (int i = pos; i < lista.contador - 1; i++) {
            lista.elementos[i] = lista.elementos[i + 1];
        }
        lista.contador--;
    }
}

string nombreCompleto(tEstudiante estudiante){
    return estudiante.nombre + " " + estudiante.apellidos; 
}

void calificar(tLista &lista){
    for (int i = 0; i< lista.contador;i++){
        cout<<"> Nota del ESTUDIANTE "<<nombreCompleto(lista.elementos[i])<<": ";
        cin>>lista.elementos[i].nota;
    }
}

double mediaClase (const tLista &lista){
    double total = 0;
    for (int i =0; i<lista.contador;i++){
        total += lista.elementos[i].nota;
    }
    return total / lista.contador;
}

int mayorNota (const tLista &lista){
    double max=0;
    int pos = 0;
    for (int i=0;i<lista.contador;i++){
        if (lista.elementos[i].nota > max){
            max = lista.elementos[i].nota;
            pos = i;
        }
    }
    return pos;
}

void mostrarEstudiante (tEstudiante estudiante){
    cout << setw(35) << left << nombreCompleto(estudiante);
    cout << estudiante.nif << " EDAD: ";
    cout << setw(2) << estudiante.edad << "  NOTA: ";
    cout << fixed << setprecision(1) << estudiante.nota;
}

void listado(const tLista &lista, double media, int mayor) {
    for (int i = 0; i < lista.contador; i++) {
        cout << i << ": ";
        mostrarEstudiante(lista.elementos[i]);
        if (i == mayor) {cout << " <<< Mayor nota!";}
        cout << endl;
    }
    cout << "Media de la clase: " << fixed << setprecision(1)<< media << endl << endl;
}

void guardar(const tLista &lista) {
    ofstream archivo;
    archivo.open("clase.txt");
    for (int i = 0; i < lista.contador; i++) {
        archivo << lista.elementos[i].nombre << endl;
        archivo << lista.elementos[i].apellidos << endl;
        archivo << lista.elementos[i].edad << endl;
        archivo << lista.elementos[i].nif << endl;
        archivo << lista.elementos[i].nota << endl;
    }
    archivo << "XXX" << endl; // Centinela final
    archivo.close();
}