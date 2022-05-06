#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "estructurass.h"

int menu_citas (int opc){
    system ("cls");
    cout<<setw(67)<<"_______________________________"<<endl;
    cout<<setw(67)<<"|          MENU CITAS          |"<<endl;
    cout<<setw(67)<<"|                              |"<<endl;
    cout<<setw(67)<<"| 1.- AGREGAR CITA             |"<<endl;
    cout<<setw(67)<<"| 2.- MODIFICAR CITA           |"<<endl;
    cout<<setw(67)<<"| 3.- ELIMINAR CITA            |"<<endl;
    cout<<setw(67)<<"| 4.- CONSULTAR CITAS          |"<<endl;
    cout<<setw(67)<<"| 5.- VOLVER AL MENU PRINCIPAL |"<<endl;
    cout<<setw(67)<<"|______________________________|"<<endl;
    cout<<"\n"<<setw(60)<<">INGRESE SU OPCION: ";
    cin>>opc;
    while (opc<1 || opc>5){
        cout<<setw(65)<<" ! INGRESE UN OPCION VALIDA !"<<endl;
        cout<<"\n"<<setw(60)<<" >INGRESE SU OPCION: ";
        cin>>opc;
    }
    system ("cls");
    return opc;
}

void cargar_citas (tLista &lista){
    tFormulario formulario;
    ifstream cargarcitas;
    lista.cont = 0;
    cargarcitas.open ("citas.txt", ios::in);
    if (!cargarcitas.is_open()){
        //cout<<setw(60)<<"! NADA AGRAGADO AUN !"<<endl;
    }
    else{
        while (!cargarcitas.eof() && lista.cont<MAX){
            getline(cargarcitas,formulario.nombre_completo);
            getline(cargarcitas,formulario.cedula);
            cargarcitas>>formulario.edad;
            cargarcitas.get();
            getline(cargarcitas, formulario.especialidad);
            cargarcitas>>formulario.dia;
            cargarcitas>>formulario.mes;
            cargarcitas>>formulario.year;
            lista.datos[lista.cont] = formulario;
            lista.cont++;
        }
        cargarcitas.close();
    }
}

void agregarcitas (tFormulario formulario, tLista &lista){
    ofstream agregar;
    agregar.open ("citas.txt", ios::out | ios::app);
    if (lista.cont < MAX){
        cout<<setw(82)<<"|-^-| INGRESO DE DATOS PARA UNA CITA |-^-|\n"<<endl;
        cout<<setw(101)<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<endl<<setw(85)<<"---------------- INFORMACION CITA -----------------"<<endl;
        cin.ignore();
        cout<<setw(53)<<"> NOMBRE COMPLETO: ";
        getline(cin,formulario.nombre_completo);
        cout<<setw(53)<<"> CEDULA: ";
        getline(cin,formulario.cedula);
        cout<<setw(53)<<"> EDAD: ";
        cin>>formulario.edad;
        while (formulario.edad < 0){
            cout<<setw(65)<<"! INGRESE NUMEROS VALIDOS !"<<endl;
            cout<<setw(50)<<"> EDAD: ";
            cin>>formulario.edad;
        }
        cin.ignore();
        cout<<setw(55)<<"> ESPECIALIDAD: ";
        getline(cin,formulario.especialidad);
        

        cout<<setw(55)<<"> FECHA (FORMATO dd-mm-aa): ";
        cin>>formulario.dia;
        cin.ignore();
        cin>>formulario.mes;
        cin.ignore();
        cin>>formulario.year;
        while ((formulario.dia<0 || formulario.dia >30) || (formulario.mes<0 || formulario.mes > 12) || (formulario.year<2020)){
            cout<<setw(65)<<"[FORMATO DE FECHA INCORRECTA]"<<endl;
            cout<<setw(55)<<"> FECHA (FORMATO dd-mm-aa): ";
            cin>>formulario.dia;
            cin.ignore();
            cin>>formulario.mes;
            cin.ignore();
            cin>>formulario.year;
        }     
        lista.datos[lista.cont] = formulario;
        agregar<<formulario.nombre_completo<<endl;
        agregar<<formulario.cedula<<endl;
        agregar<<formulario.edad<<endl;
        agregar<<formulario.especialidad<<endl;
        agregar<<formulario.dia<<" "<<formulario.mes<<" "<<formulario.year<<endl;
        lista.cont++;
    }
    else{
        cout<<"! IMPOSIBLE LLENAR AGENDAR CITAS !"<<endl;
    }
    agregar.close();
}

void modificar_citas (tLista &lista){
    int i = 0, ok = 0;
    bool val = true;
    string aux, especialidad;
    int anio = 0, mes = 0, dia = 0;
    cout<<setw(82)<<"|-^-| MODIFICAR CITA MEDICA|-^-|\n"<<endl;
    cin.ignore();
    cout <<" > INGRESE LA CEDULA DEL PACIENTE: ";
    getline (cin,aux);
    while(val == true){
        if (lista.datos[i].cedula== aux){
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout<<setw(76)<<"[-]  CITA ENCONTRADA  [-] "<<endl;
            cout <<setw(53)<< "NOMBRE: " << lista.datos[i].nombre_completo<<endl;
            cout <<setw(53)<< "APELLIDO: " << lista.datos[i].cedula<<endl;
            cout <<setw(53)<< "EDAD: " << lista.datos[i].edad<<endl;
            cout <<setw(53)<< "ESPECIALIDAD: " << lista.datos[i].especialidad<<endl;
            cout <<setw(53)<< "FECHA: " << lista.datos[i].year<<lista.datos[i].mes<<lista.datos[i].dia<<endl;
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            cout <<setw(74)<<"[-]  INGRESE LOS NUEVOS DATOS  [-]" <<endl;
            cout <<setw(53)<< "> ESPECIALIDAD: ";
            cin >> especialidad;
            cout <<setw(53)<< "> FECHA: ";
            cin>>anio;
            cin.ignore();
            cin>>mes;
            cin.ignore();
            cin>>dia;
            while ((dia<0 || dia >30) || (mes<0 ||mes > 12) || (anio<2020)){
                cout<<setw(65)<<"[FORMATO DE FECHA INCORRECTA]"<<endl;
                cout<<setw(55)<<"> FECHA (FORMATO dd-mm-aa): ";
                cin>>dia;
                cin.ignore();
                cin>>mes;
                cin.ignore();
                cin>>anio;
            }
            cout<<setw(80)<<"-----------------------------------------------"<<endl;
            val = false;
            i++;
            cout << setw(53)<< "ESTA SEGURO QUE DESEA MODIFICAR LA CITA MEDICA"<<endl;
            cout <<setw(65)<<"1. SI" << endl;
            cout <<setw(65)<<"2. NO" << endl;
            cout <<setw(65)<<"> INGRESE SU OPCION: " << endl;
            cin >> ok;
        }
    }
    if (val == false && ok == 1){
        lista.datos[i].especialidad = especialidad;
        lista.datos[i].year = anio;
        lista.datos[i].mes = mes;
        lista.datos[i].dia = dia;
        cout<<setw(65)<<"! CITA MODIFICADA EXITOSAMENTE !"<<endl;
    }
    else if (ok == 2){
        cout <<setw(65)<< "LA CITA NO HA SIDO MODIFICADA" << endl;
    }
    else{
        cout<<setw(65)<<"! NO SE ENCONTRO EL PACIENTE !"<<endl;
    }
    sleep(5);
}

void eliminar_citas (tLista &lista){
    string aux;
    bool b;
    int ok = 0;
    cout<<setw(82)<<"|-^-| ELIMINAR CITA |-^-|\n"<<endl;
    cout << "> INGRESE LA CEDULA DEL PACIENTE: ";
    cin >> aux;
    cout <<setw(45)<<"> ESTA SEGURO DE ELIMINAR LA CITA" << endl;
    cout <<setw(65)<<"1. ELIMINAR CITA" << endl;
    cout <<setw(65)<<"2. NO ELIMINAR" << endl;
    cout <<setw(65)<<"> INGRESE SU OPCION: " << endl;
    cin >> ok;
    switch (ok){
        case 1:{
            for (int i = 0; i < lista.cont; i++){
                b= true;
                if (lista.datos[i].cedula == aux){
                    lista.datos[i] = lista.datos[i + 1];
                    lista.cont--;
                    cout<<setw(65)<<"! CITA ELIMINADO EXITOSAMENTE !"<<endl;
                }
                else {
                    b = false;
                    cout << setw(65)<<"! CITA INEXISTENTE !" << endl;
                }
            }   
        }
        break;
        case 2:
            cout << "NO SE HA ELMINADO SU CITA PREVIA" << endl;
        break;
    }
    sleep (4);
}