#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <fstream>
#include <unistd.h>
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

//PROTOTIPOS DE MENÚS
void titulo ();
int menu_principal (int op);
int menu_medicos (int opm);

//MEDICOS
void agregar_medicos (tDoctor doctor, tLista2 &lista2);
void cargar_medicos (tLista2 &lista2);
void modificar_medicos(tLista2 &lista2);
void eliminar_medicos (tLista2 &lista2);
void archivar_medicos (tLista2 &lista2);
void ordenar_medicos (tLista2 &lista2);
void mostrar_medicos (tLista2 &lista2);

//CITAS
int menu_citas (int opc);
void cargar_citas (tLista &lista);
void agregarcitas (tFormulario formulario, tLista &lista);
void modificar_citas (tLista &lista);
void eliminar_citas (tLista &lista);
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

//MEDICOS
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


// CITAS
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