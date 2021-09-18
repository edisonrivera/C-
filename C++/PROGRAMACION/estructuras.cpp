#include <iostream>
#include <cstring>
using namespace std;
#include <fstream>
const int MAX = 100;
//EQUIPOS
typedef struct{
    string equipo;
    int ganados;
    int empatados;
    int puntos;
}tEquipo;

typedef struct{
    tEquipo datos[MAX];
    int cont;
}tLista;
//ANIMALES
typedef struct{
    string animal;
    float peso;
    string tipo;
}tAnimales;

typedef struct{
    int contador;
    tAnimales archivos[MAX];
}tLista2;
//BECARIOS
typedef struct{
    string nombreEmpleado;
    int edadE;
    string titulo;
    string contratacion;
}tPersonal; 
tPersonal personal[MAX];
//FECHAS
struct Fechas{
    int dia;
    int mes;
    int anio;
}fecha1, fecha2;

//PRINCIPAL
int menu(int opx);
//TERMINADO PROBLEMA "EQUIPOS"
int submenu (int opc);
void equipos (tEquipo ligas,tLista &lista);
void estadisticas (tEquipo ligas, tLista &lista);
//TERMINADO PROBLEMA "ANIMALES"
int submenu2 (int opz);
void cargar (tLista2 &lista2);
void animaleslista (tAnimales animales, tLista2 &lista2);
void basededatos (tAnimales animales, tLista2 &lista2);
void buscaranimal (tLista2 &lista2);
//TERMINADO PROBLEMA "BECARIOS"
int ingresarpersonal(tPersonal personal[]);
void mostrarpersonal(tPersonal personal[], int x);
//PROBLEMA FECHAS
void ingresarfechas (Fechas);
int fechamayor (Fechas);
void mostrarfecha(Fechas, int eval);
int main (){
    tEquipo ligas;
    tLista lista;
    tAnimales animales;
    tLista2 lista2;
    tPersonal personal[MAX];
    Fechas fecha;
    lista.cont = 0;
    lista2.contador = 0;
    int op = 0;
    while (op!=5){
        op = menu(op);
        switch (op){
            case 1:{
                int num =0;
                while (num != 3){
                    num = submenu (num);
                    switch (num){
                    case 1:
                        equipos (ligas,lista);
                        break;
                    case 2:
                        estadisticas(ligas,lista);
                        break;
                    case 3:
                        break;
                    }                   
                }
            }  
            break;
            case 2:{
                int oph = 0;
                while(oph!=4){
                    cargar (lista2);
                    oph = submenu2(oph);
                    switch (oph){
                    case 1:
                        animaleslista (animales,lista2);
                        break;
                    case 2:
                        basededatos (animales,lista2);
                        break;
                    case 3:
                    buscaranimal (lista2);
                        break;
                    case 4:
                        break;
                    }
                }  
            }
            break;
            case 3:{
                int veces = 0;
                veces = ingresarpersonal(personal);
                mostrarpersonal(personal,veces);
            }
            break;
            case 4:{
                int evaluar = 0;
                ingresarfechas(fecha);
                evaluar = fechamayor(fecha);
                mostrarfecha(fecha, evaluar);
            }
            break;   
            case 5:
                exit(5);
            break;
        }
    }
    return 0;
}
//TERMINADO PRINCIPAL
int menu(int opx){
    cout<<"\t\t\tM E N U   P R I N C I P A L"<<endl;
    cout<<"1.- EQUIPOS"<<endl;
    cout<<"2.- ANIMALES"<<endl;
    cout<<"3.- BECARIOS"<<endl;
    cout<<"4.- FECHAS"<<endl;
    cout<<"5.- SALIR"<<endl;
    cout<<"> Ingrese su opcion: ";
    cin>>opx;
    while (opx<1 || opx>5){
        cout<<"\t\t[NO EXISTE ESA OPCION]"<<endl;
        cout<<"> Ingrese su opcion: ";
        cin>>opx;
    } 
    return opx;
}

//TERMINADO PROBLEMA "EQUIPOS"
int submenu (int opc){
    cout<<endl<<"\t--------------------------------------------------------------"<<endl;
    cout<<"\t\t\t > M E N U : EQUIPOS"<<endl;
    cout<<"1.- AGREGAR"<<endl;
    cout<<"2.- CONSULTAR ESTADISTICAS"<<endl;
    cout<<"3.- SALIR"<<endl;
    cout<<"> Ingrese su opcion: ";
    cin>>opc;
    while (opc<1 || opc>3){
        cout<<"\t\t[NO EXISTE ESA OPCION]"<<endl;
        cout<<"> Ingrese su opcion: ";
        cin>>opc;
    }
    cout<<endl<<"\t--------------------------------------------------------------"<<endl; 
    return opc;
}

void equipos (tEquipo ligas,tLista &lista){
    int puntaje = 0;
    cin.sync();
    if (lista.cont<MAX){
        cout<<"\t\t\t- 1) EQUIPOS :AGREGAR-"<<"\t\t\t #"<<lista.cont+1<<endl;
        cout<<"\t> Nombre del EQUIPO: ";
        getline(cin,ligas.equipo);
        cout<<"\t> Cantidad de partidos GANADOS: ";
        cin>>ligas.ganados;
        while (ligas.ganados<0){
            cout<<"\t\t[INGRESE VALORES POSITIVOS]"<<endl;
            cout<<"\t> Cantidad de partidos GANADOS: ";
            cin>>ligas.ganados;
        }
        cout<<"\t> Cantidad de partidos EMPATADOS: ";
        cin>>ligas.empatados;
        while (ligas.empatados<0){
            cout<<"\t\t[INGRESE VALORES POSITIVOS]"<<endl;
            cout<<"\t> Cantidad de partidos EMPATADOS: ";
            cin>>ligas.empatados;
        }
        cout<<"\t--------------------------------------------------------------"<<endl;
        ligas.puntos = (ligas.ganados*3)+(ligas.empatados);
        lista.datos[lista.cont] = ligas;
        lista.cont ++;
    }
    else{
        cout<<"\t\t[L I S T A  L L E N A]"<<endl;
    }
}

void estadisticas (tEquipo ligas, tLista &lista){
    int max=0,min=0,aux=0,i=0,j=0;
    
    for (i =0; i<lista.cont;i++){
        min = i;
        for (j =i+1;j<lista.cont;j++){
            if (lista.datos[j].puntos < lista.datos[min].puntos){
                min = j;
            }
        }
        aux = lista.datos[i].puntos;
        lista.datos[i].puntos = lista.datos[min].puntos;
        lista.datos[min].puntos = aux;
    }
    cout<<"\t--------------------------------------------------------------"<<endl;
    cout<<"\t\t 2) EQUIPOS: ORDEN DE LOS PUNTAJES"<<endl;
    for (int i=0;i<lista.cont;i++){
        cout<<"\t\t\tPOSICION ["<<i+1<<"]: "<<lista.datos[i].puntos<<endl;
    }
}

//TERMINADO PROBLEMA "ANIMALES"
int submenu2 (int opz){
    cout<<endl<<"\t--------------------------------------------------------------"<<endl;
    cout<<"\t\t\t > M E N U : ANIMALES"<<endl;
    cout<<"1.- REGISTRAR ANIMAL"<<endl;
    cout<<"2.- BASE DE DATOS DEL ZOO"<<endl;
    cout<<"3.- BUSCAR ANIMAL"<<endl;
    cout<<"4.- SALIR"<<endl;
    cout<<"> Ingrese su opcion: ";
    cin>>opz;
    while (opz<1 || opz>4){
        cout<<"\t\t[NO EXISTE ESA OPCION]"<<endl;
        cout<<"> Ingrese su opcion: ";
        cin>>opz;
    }
    cout<<endl<<"\t--------------------------------------------------------------"<<endl; 
    return opz;    
}

void animaleslista (tAnimales animales, tLista2 &lista2){
    int identificacion = 0;
    string animal ,tipo;
    float peso; 
    ofstream ingresaranimales;
    ingresaranimales.open("archivo.txt",ios::out | ios::app);
    if (lista2.contador<MAX){
        cout<<"\t\t\t- 1) ANIMALES : AGREGAR-"<<"\t\t #"<<lista2.contador<<endl;
        cin.ignore();
        cout<<"\t> Nombre del ANIMAL: ";
        getline(cin,animales.animal);
        cout<<"\t> Peso (kg): ";
        cin>>animales.peso;
        while (animales.peso<0){
            cout<<"\t\t[INGRESE VALORES POSITIVOS]"<<endl;
            cout<<"\t> Peso (kg): ";
            cin>>animales.peso;
        }
        cin.ignore();
        cout<<"\t> Tipo de ANIMAL: ";
        getline(cin,animales.tipo);
        lista2.contador++;
        lista2.archivos[lista2.contador] = animales;
        ingresaranimales<<animales.animal<<endl;
        ingresaranimales<<animales.peso<<endl;  
        ingresaranimales<<animales.tipo<<endl;
        cout<<endl<<"\t--------------------------------------------------------------"<<endl; 
    }
    else {
        cout<<"\t\t\t[L I S T A  L L E N A]"<<endl;
    }
    ingresaranimales.close();
}

void basededatos (tAnimales animales, tLista2 &lista2){
    int identificacion = 0;
    string animal ,tipo;
    float peso;
    ifstream leerarchivo;
    leerarchivo.open ("archivo.txt", ios::in);
    cout<<"\t\t\t -----> BASE DE DATOS <-----"<<endl;
    if (!leerarchivo.is_open()){
        cout<<"\t\t[NADA AGREGADO AUN]"<<endl;
    }
    else{
        while (!leerarchivo.eof()){
            getline(leerarchivo,animal);
            leerarchivo>>peso;
            leerarchivo.get();
            getline(leerarchivo,tipo);
            if (!leerarchivo.eof()){
                cout<<"\t\t----------------  IDENTIFICADOR: ["<<identificacion+1<<"] -----------"<<endl;
                cout<<"\t\t> NOMBRE DEL ANIMAL: "<<animal<<endl;
                cout<<"\t\t> PESO DEL ANIMAL: "<<peso<<endl;
                cout<<"\t\t> TIPO DE ANIMAL: "<<tipo<<endl;
                cout<<"\t\t------------------------------------------------"<<endl;
                lista2.archivos[lista2.contador] = animales;
                identificacion++;
            }
        }
    }

    leerarchivo.close();
}

void buscaranimal (tLista2 &lista2){
    string banimal;
    bool band = true;
    lista2.contador = 0;
    cout<<"\t\t2) ANIMALES: BUSCAR"<<endl;
    cin.ignore();
    cout<<"\t> Ingrese el nombre del animal: ";
    getline(cin,banimal);
    while (band == true && lista2.contador < MAX){
        if (lista2.archivos[lista2.contador].animal == banimal){
            band = false;
        }
        lista2.contador++;
    }
    if (band == false){
        cout<<"\t\t----------------  IDENTIFICADOR: ["<<lista2.contador<<"] -----------"<<endl;
        cout<<"\t\t> NOMBRE DEL ANIMAL: "<<lista2.archivos[lista2.contador-1].animal<<endl;
        cout<<"\t\t> PESO DEL ANIMAL: "<<lista2.archivos[lista2.contador-1].peso<<endl;
        cout<<"\t\t> TIPO DE ANIMAL: "<<lista2.archivos[lista2.contador-1].tipo<<endl;
        cout<<"\t\t------------------------------------------------"<<endl;
    }
    else{
        cout<<"\t\t\t[ANIMAL NO ENCOTRADO]"<<endl;
    }

}

void cargar (tLista2 &lista2){
    tAnimales animales;
    ifstream archivo;
    lista2.contador = 0;
    archivo.open ("archivo.txt");
    if (!archivo.is_open()){
    }
    else{
        while (!archivo.eof() && lista2.contador<MAX){
            getline(archivo,animales.animal);
            archivo>>animales.peso;
            archivo.get();
            getline(archivo,animales.tipo);
            lista2.archivos[lista2.contador] = animales;
            lista2.contador++;
        }
        archivo.close();
    }
}

//TERMINADO PROBLEMA "BECARIOS" 
int ingresarpersonal(tPersonal personal[]){
    char letra;
    string empleado, titulo, contrato;
    int edad=0,i=0;
    cout<<"\t\t -----------------------------------------------------"<<endl;
    cout<<"\t\t\t\t B E C A R I O S "<<endl;
    do{
        cout<<"\t\t ------------ INFORMACION EMPLEADOS ["<<i<<"] --------------"<<endl;
        cin.ignore();
        cout<<"\t\t > NOMBRE: ";
        getline(cin,personal[i].nombreEmpleado);
        cout<<"\t\t > EDAD: ";
        cin>>edad;
        while (edad<=0){
            cout<<"\t\t [INGRESE VALORES MAYORES A 0]"<<endl;
            cout<<"\t\t > EDAD: ";
            cin>>edad;
        }
        personal[i].edadE = edad;
        cin.ignore();
        cout<<"\t\t > GRADO DE ESTUDIO: ";
        getline(cin,personal[i].titulo);
        cout<<"\t\t > TIPO DE CONTRATACION: ";
        getline(cin,personal[i].contratacion);
        i++;
        cout<<"\t\t Desea ingresar otro contacto? (s/n): ";
        cin>>letra;
    } while(letra == 's' && i<MAX);
    if (i>=MAX){
        cout<<"\t\t\t[L I S T A   L L E N A]"<<endl;
    }
    cout<<"\t\t -----------------------------------------------------"<<endl;
    return i;
}

void mostrarpersonal(tPersonal personal[], int x){
    int i = 0;
    cout<<"\t\t ------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t DATOS DEL PERSONAL"<<endl;
    for (int i = 0;i<x;i++){
       cout<<"\t\t > NOMBRE: "<<personal[i].nombreEmpleado<<"\t> TITULACION: "<<personal[i].titulo<<endl; 
    }
    cout<<"\t\t ------------------------------------------------------"<<endl;
}

//PROBLEMA "FECHAS"
void ingresarfechas (Fechas){
    cout<<"\t---------------------------------------------------------"<<endl;
    cout<<"\t\t\t F E C H A S"<<endl;
    cout<<"\t > Ingrese la primera fecha (dia-mes-anio): ";
    cin>>fecha1.dia;
    cin.ignore();
    cin>>fecha1.mes;
    cin.ignore();
    cin>>fecha1.anio;
    while ((fecha1.dia<0 || fecha1.dia>31) || (fecha1.mes<0 || fecha1.mes>12) || (fecha1.anio<0)){
        cout<<"\t\t\t[FORMATO DE FECHA INCORRECTA]"<<endl;
        cout<<"\t > Ingrese la primera fecha (dia-mes-anio): ";
        cin>>fecha1.dia;
        cin.ignore();
        cin>>fecha1.mes;
        cin.ignore();
        cin>>fecha1.anio;
    }
    cout<<endl<<"\t > Ingrese la segunda fecha (dia-mes-anio): ";
    cin>>fecha2.dia;
    cin.ignore();
    cin>>fecha2.mes;
    cin.ignore();
    cin>>fecha2.anio;
    while ((fecha2.dia<0 || fecha2.dia>31) || (fecha2.mes<0 || fecha2.mes>12) || (fecha2.anio<0)){
        cout<<"\t\t\t[FORMATO DE FECHA INCORRECTA]"<<endl;
        cout<<"\t > Ingrese la segunda fecha (dia-mes-anio): ";
        cin>>fecha2.dia;
        cin.ignore();
        cin>>fecha2.mes;
        cin.ignore();
        cin>>fecha2.anio;
    }
}

int fechamayor (Fechas){
    int s = 0;
    if (fecha1.anio > fecha2.anio){s+=5;}
    else if (fecha1.anio < fecha2.anio){s-=5;}
    if (fecha1.mes > fecha2.mes){s+=2;}
    else if (fecha1.mes < fecha2.mes){s-=2;}
    if (fecha1.dia > fecha2.dia){s++;}
    else if(fecha1.dia < fecha2.dia){s--;};
    if ((fecha1.anio == fecha2.anio) && (fecha1.mes == fecha2.mes) && (fecha1.dia == fecha2.dia)){s = 0;}
    return s;
}

void mostrarfecha(Fechas, int eval){
    cout<<endl;
    if (eval == 0){
        cout<<"\t\t\t[LAS FECHAS SON IGUALES]"<<endl;
    }
    else if (eval > 0){
        cout<<"\t\t > La fecha mayor es: ";
        if (fecha1.dia < 10){cout<<"0"<<fecha1.dia;}
        else{cout<<fecha1.dia;}
        cout<<"-";
        if (fecha1.mes < 10){cout<<"0"<<fecha1.mes;}
        else{cout<<fecha1.mes;}
        cout<<"-";
        cout<<fecha1.anio;
    }
    else if (eval < 0) {
        cout<<"\t\t > La fecha mayor es: ";
        if (fecha2.dia < 10){cout<<"0"<<fecha2.dia;}
        else{cout<<fecha2.dia;}
        cout<<"-";
        if (fecha2.mes < 10){cout<<"0"<<fecha2.mes;}
        else{cout<<fecha2.mes;}
        cout<<"-";
        cout<<fecha2.anio;
    }
    cout<<endl<<"\t---------------------------------------------------------"<<endl;
}