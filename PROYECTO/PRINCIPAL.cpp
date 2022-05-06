#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "estructurass.h"
#include "medicos.h"
#include "citas.h"

void titulo ();
int menu_principal (int op);
int menu_medicos (int opm);

int main (){
    tFormulario formulario;
    tLista lista;
    tDoctor doctor;
    tLista2 lista2;
    int op = 0;
    while (op != 3){
        titulo();
        op = menu_principal(op);
        switch (op){
        case 1:{
            int opm = 0;
            cargar_medicos (lista2);
            while (opm !=5){
                opm = menu_medicos(opm);
                switch(opm){
                    case 1:
                        agregar_medicos(doctor,lista2);
                    break;
                    case 2:
                        modificar_medicos (lista2);
                    break;
                    case 3: 
                        eliminar_medicos (lista2);
                    break;
                    case 4:
                        ordenar_medicos (lista2);
                        mostrar_medicos (lista2);
                    break;
                }
                archivar_medicos (lista2);
            }
        }
            break;
        case 2:{
            int opc = 0;
            cargar_citas (lista);
            while (opc != 5){
                opc = menu_citas(opc);
                switch (opc){
                    case 1:
                        agregarcitas(formulario,lista);
                    break;
                    case 2:
                        modificar_citas (lista);
                    break;
                    case 3: 
                        eliminar_citas (lista);
                    break;
                    case 4: {}
                    break;
                }
            }
        }
            break;
        case 3:
            exit (3);
            break;
        default:
            break;
        } 
    }
    system ("pause");
    return 0; 
}

//DESARROLLO DE MENÚS
void titulo (){
    cout<<setw(70)<<"|-^-|\t HOSPITAL GENERAL DEL SUR\t|-^-|\n";
    cout<<setw(80)<<"------------------------------------------------------"<<endl;
    cout<<setw(74)<<"! SOFTWARE DE GESTION DE CITAS MEDICAS !"<<endl;
    cout<<setw(80)<<"------------------------------------------------------"<<endl;
}

int menu_principal (int op){
    cout<<setw(67)<<"______________________________"<<endl;
    cout<<setw(67)<<"|       MENU PRINCIPAL       |"<<endl;
    cout<<setw(67)<<"|                            |"<<endl;
    cout<<setw(67)<<"| 1.- INFORMACION DE MEDICOS |"<<endl;
    cout<<setw(67)<<"| 2.- CONSULTA DE CITAS      |"<<endl;
    cout<<setw(67)<<"| 3.- SALIR DEL PROGRAMA     |"<<endl;
    cout<<setw(67)<<"|____________________________|"<<endl;
    cout<<"\n"<<setw(60)<<">INGRESE SU OPCION: ";
    cin>>op;
    while (op<1 || op>3){
        cout<<setw(65)<<" ! INGRESE UN OPCION VALIDA !"<<endl;
        cout<<"\n"<<setw(60)<<" >INGRESE SU OPCION: ";
        cin>>op;
    }
    return op;
}