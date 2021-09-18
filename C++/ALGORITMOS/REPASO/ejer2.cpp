#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 100;
struct empleado
{
    string nombre;
    string apellido;
    int edad = 0;
    double sueldo = 0;
    int anios = 0;
    string ok = "si";
    double nuevoSueldo = 0; 
}personal;
struct inventario
{
    empleado personal [MAX];
    int cont;
}lista;
int menu();
void cargar (inventario& lista, bool a);
void mostrarElementos (const inventario lista);
void leerEmpleado (inventario& lista, int num);

int main (){
    int numEmpleado = 0;
    inventario lista;
    int op = menu();
    bool a;
    while (op != 3){
        
        switch (op)
        {
        case 1:
            {
                cout << "\t\t\t C O C A  C O L A\n";
                cout << "Ingrese el numero de empleados: ";
                cin >> numEmpleado;
                leerEmpleado (lista,numEmpleado);    
            }
            break;
        case 2:
            {
                cargar (lista, a);            
            }
            break;
        }
        op = menu();
    }
    
    system ("pause");
    return 0;
}
int menu (){
    int op = -1;
    while (op < 1 || op > 3){
        cout <<setw(72)<<"________________________________" << endl;
        cout <<setw(72)<<"|          EMPLEADOS            |" << endl;
        cout <<setw(72)<<"|                               |"<<endl;
        cout <<setw(72)<<"| 1.- AGREGAR EMPLEADOS         |" << endl;
        cout <<setw(72)<<"| 2.- VER EMPELADOS             |" << endl;
        cout <<setw(72)<<"| 3.- SALIR                     |" << endl;
        cout <<setw(72)<<"|_______________________________|" << endl;
        cout <<"\n"<<setw(60)<<"- INGRESE SU OPCION: ";
        cin >> op;
        if ( op < 1 || op > 3){
            cout <<setw(70)<<"- LA OPCION NO ES VALIDA -" << endl;
        }
    }
    return op;
}
void cargar (inventario& lista, bool a){
    empleado persona;
    ifstream archivo;
    lista.cont = 0;
    string texto;
    archivo.open("Empleados.txt", ios::in );
    if (archivo.fail()){
        a = false;
    }
    else{
        a = true;
        while (!archivo.eof()){
            getline(archivo, texto);
            cout << texto << endl;
        }
    }
    archivo.close ();
}

void leerEmpleado (inventario& lista, int num){
    ofstream archivo;
    empleado persona;
    lista.cont = 0;
    archivo.open("Empleados.txt", ios :: out | ios :: app);
    archivo << "\t\t ---C O C A - C O L A---\n" ;
    archivo << "\t --R e p o r t e   d e  S a l a r i o s--\n" ;
    for (int i = 0; i < num; i++){
        cout << "------------------------------------------------------------" << endl;
        cin.ignore();
        cout << "\t > Ingrese la informacion del empleado " << i + 1 << endl;
        cout << "\t > Nombre: ";
        getline (cin, persona.nombre);
        cout << "\t > Apellido: ";
        getline (cin, persona.apellido);
        cout << "\t > Edad: ";
        cin >> persona.edad;
        cout << "\t > Sueldo: ";
        cin >> persona.sueldo;
        cout << "\t > Anios trabajando: ";
        cin >> persona.anios;
        
        if(persona.anios> 10){
            persona.nuevoSueldo = persona.sueldo + persona.sueldo * 0.10;
        }
        else if(persona.anios > 5 && lista.personal[i].anios < 10){
            persona.nuevoSueldo = persona.sueldo + persona.sueldo  * 0.07;
        }
        else if (persona.anios > 3 && lista.personal[i].anios < 5){
            persona.nuevoSueldo = persona.sueldo + persona.sueldo  * 0.05; 
        }
        else if(persona.anios > 0 && lista.personal[i].anios < 3){
            persona.nuevoSueldo = persona.sueldo + persona.sueldo  * 0.03; 
        }
        lista.personal[lista.cont] = persona;
        lista.cont++;
        archivo << "------------------------------------------------------------" << endl;
        archivo <<"\t > Nombre: " <<lista.personal[i].nombre << endl;
        archivo <<"\t > Apellido: "<<lista.personal[i].apellido << endl;
        archivo <<"\t > Ead: " <<lista.personal[i].edad << endl;
        archivo <<"\t > Sueldo: " <<lista.personal[i].sueldo << endl; 
        archivo <<"\t > Años trabajando: " <<lista.personal[i].anios << endl; 
        archivo <<"\t > Recibe ganancias: " <<lista.personal[i].ok << endl;
        archivo <<"\t > Nuevo sueldo: " <<lista.personal[i].nuevoSueldo<< endl;
        archivo << "------------------------------------------------------------" << endl;
    } 
    archivo.close();
}

