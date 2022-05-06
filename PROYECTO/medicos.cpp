#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "estructurass.h"

int menu_medicos (int opm){
    system ("cls");
    cout<<setw(67)<<"_______________________________"<<endl;
    cout<<setw(67)<<"|          MENU MEDICOS        |"<<endl;
    cout<<setw(67)<<"|                              |"<<endl;
    cout<<setw(67)<<"| 1.- AGREGAR INFORMACION      |"<<endl;
    cout<<setw(67)<<"| 2.- MODIFICAR INFORMACION    |"<<endl;
    cout<<setw(67)<<"| 3.- ELIMINAR INFORMACION     |"<<endl;
    cout<<setw(67)<<"| 4.- MOSTRAR ORDENADAMENTE    |"<<endl;
    cout<<setw(67)<<"| 5.- VOLVER AL MENU PRINCIPAL |"<<endl;
    cout<<setw(67)<<"|______________________________|"<<endl;
    cout<<"\n"<<setw(60)<<">INGRESE SU OPCION: ";
    cin>>opm;
    while (opm<1 || opm>5){
        cout<<setw(65)<<" ! INGRESE UN OPCION VALIDA !"<<endl;
        cout<<"\n"<<setw(60)<<" >INGRESE SU OPCION: ";
        cin>>opm;
    }
    system ("cls");
    return opm;
}

void cargar_medicos (tLista2 &lista2){
    tDoctor doctor;
    ifstream cargardoctores;
    lista2.cont2 = 0;
    char aux;
    cargardoctores.open ("medicos.txt", ios::in);
    if (!cargardoctores.is_open()){
    }
    else{
        while (!cargardoctores.eof() && lista2.cont2<MAX){
            getline(cargardoctores, doctor.nombre);
            getline(cargardoctores, doctor.apellido);
            getline(cargardoctores, doctor.nif);
            getline(cargardoctores, doctor.titulo);
            cargardoctores.get(aux);
            lista2.datosDoctor[lista2.cont2] = doctor;
            lista2.cont2++;
        }
        cargardoctores.close();
    }
}

void agregar_medicos (tDoctor doctor, tLista2 &lista2){
    int i = 0, controlar = 0;
    cout<<setw(82)<<"|-^-| INGRESO DE DATOS DEL PERSONAL MEDICO |-^-|\n"<<endl;
    if (lista2.cont2<MAX){
        cout<<setw(65)<<"----------- DATOS DEL MEDICO #"<<lista2.cont2<<" ------------"<<endl;
        cin.ignore();
        cout<<setw(45)<<"> NOMBRE: ";
        getline (cin,doctor.nombre);
        cout<<setw(47)<<"> APELLIDO: ";
        getline (cin,doctor.apellido);
        cout<<setw(45)<<"> CEDULA: ";
        getline(cin,doctor.nif);
        while ((controlar == 0) && (i<lista2.cont2)){
            if (doctor.nif == lista2.datosDoctor[i].nif){controlar++;}
            i++;
        }
        if (controlar != 0){
            cout<<setw(79)<<"--------------------------------------------"<<endl;
            cout<<setw(65)<<"! CEDULA YA REGISTRADA !"<<endl;
            sleep (5);
            system ("cls");
        }
        else{
            cout<<setw(51)<<"> ESPECIALIDAD: ";
            getline(cin,doctor.titulo);
            lista2.datosDoctor[lista2.cont2] = doctor;
            lista2.cont2++;
            cout<<setw(79)<<"--------------------------------------------"<<endl;
            cout<<setw(67)<<"! REGISTRO EXITOSO !"<<endl;
            sleep (5);
            system ("cls");
        }
    }
    else{
        cout<<setw(79)<<"--------------------------------------------"<<endl;
        cout<<setw(75)<<"! LISTA DE MEDICOS LLENA !"<<endl;
    }
}

void modificar_medicos (tLista2 &lista2){
    int i = 0;
    bool band = true;
    string aux;
    cout<<setw(82)<<"|-^-| MODIFICAR DATOS DEL PERSONAL MEDICO |-^-|\n"<<endl;
    cin.ignore();
    cout <<" > INGRESE LA CEDULA DEL MEDICO QUE DESEA MODIFICAR: ";
    getline (cin,aux);
    while(band == true){
        if (lista2.datosDoctor[i].nif == aux){
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout<<setw(76)<<"[-]  DATOS DEL MEDICO ENCONTRADO  [-] "<<endl;
            cout <<setw(53)<< "NOMBRE: " << lista2.datosDoctor[i].nombre<<endl;
            cout <<setw(53)<< "APELLIDO: " << lista2.datosDoctor[i].apellido<<endl;
            cout <<setw(53)<< "NIF: " << lista2.datosDoctor[i].nif<<endl;
            cout <<setw(53)<< "TITULO: " << lista2.datosDoctor[i].titulo<<endl;
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout <<setw(74)<<"[-]  INGRESE LOS NUEVOS DATOS  [-]" <<endl;
            cout <<setw(53)<< "> NOMBRE: ";
            cin >> lista2.datosDoctor[i].nombre;
            cout <<setw(53)<< "> APELLIDO: ";
            cin >> lista2.datosDoctor[i].apellido;
            cout <<setw(53)<< "> TITULO: ";
            cin >> lista2.datosDoctor[i].titulo;
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            band = false;
            i++;
        }
    }
    if (band == false){
        cout<<setw(65)<<"! DATOS CAMBIADOS EXITOSAMENTE !"<<endl;
    }
    else{
        cout<<setw(65)<<"! NO SE ENCONTRO EL MEDICO !"<<endl;
    }
    sleep(5);
}

void eliminar_medicos (tLista2 &lista2){
    string aux;
    bool a = true;
    int i = 0;
    cout<<setw(82)<<"|-^-| ELIMINAR DATOS DEL PERSONAL MEDICO |-^-|\n"<<endl;
    cout << "> INGRESE LA CEDULA DEL MEDICO QUE DESEA ELIMINAR: ";
    cin >> aux;
    while(a == true && i < lista2.cont2){
        if (lista2.datosDoctor[i].nif == aux){
        	lista2.datosDoctor[i] = lista2.datosDoctor[i + 1];
            lista2.cont2--;
            cout<<setw(67)<<"! DOCTOR ELIMINADO EXITOSAMENTE !"<<endl;
            a = false;
	    }
	    else {
            cout << setw(70)<<"! DOCTOR INEXISTENTE !" << endl;
	    }
        i++;
    }
    sleep (4);
}

void ordenar_medicos (tLista2 &lista2){
    tDoctor aux2;
    string aux;
    for (int i = 0;i<lista2.cont2;i++){
        for (int j = 0;j<lista2.cont2-1;j++){
            if (lista2.datosDoctor[j].apellido > lista2.datosDoctor[j+1].apellido){
                aux = lista2.datosDoctor[j].apellido;
                aux2 = lista2.datosDoctor[j];
                lista2.datosDoctor[j].apellido = lista2.datosDoctor[j+1].apellido;
                lista2.datosDoctor[j] = lista2.datosDoctor[j+1];
                lista2.datosDoctor[j+1] = aux2;
                lista2.datosDoctor[j+1].apellido = aux;
            }
        }
    }
}

void mostrar_medicos (tLista2 &lista2){
    for (int i = 0;i<lista2.cont2;i++){
        cout<<setw(50)<<"---------------- DOCTOR #"<<i<<" ------------"<<endl;
        cout<<setw(50)<<"> NOMBRE: "<<lista2.datosDoctor[i].nombre<<endl;
        cout<<setw(50)<<"> APELLIDO: "<<lista2.datosDoctor[i].apellido<<endl;
        cout<<setw(50)<<"> CEDULA : "<<lista2.datosDoctor[i].nif<<endl;
        cout<<setw(50)<<"> ESPECIALIDAD: "<<lista2.datosDoctor[i].titulo<<endl;
    }
    sleep(5);
}

void archivar_medicos (tLista2 &lista2){
    ofstream archivar;
    archivar.open("medicos.txt", ios::out);
    for (int i = 0;i<lista2.cont2;i++){
        archivar<<lista2.datosDoctor[i].nombre<<endl;
        archivar<<lista2.datosDoctor[i].apellido<<endl;
        archivar<<lista2.datosDoctor[i].nif<<endl;
        archivar<<lista2.datosDoctor[i].titulo<<endl;
    }
    archivar.close();
}
