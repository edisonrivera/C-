#include <iostream>
using namespace std;
#include <fstream>
const int Tam = 12;
string mes [Tam] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
int menu_principal ();
int menu();
void meses(double Meses [Tam],string listameses[Tam]);
void buscar(double Meses[Tam]);
void intercambio ();
int opcion2(int longitud);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
int main (){
    cout << "\t\tTRABAJO EN GRUPO" << endl;
    cout << "\tALGORITMOS Y ESTRUCTURA DE DATOS\n" << endl;
    int opcion = menu_principal();
    while (opcion != 4){
        switch (opcion){
            case 1:{
                intercambio ();
                break;
            }
            case 2:{
                int n =0;
                n = opcion2 (n);
                int arreglo [n];
                llenar (n,arreglo);
                Ordenar (n,arreglo);
                break;
            }   
            case 3:{
                double cantidad [Tam];
                cout<< "\t-----------------------------------------------------"<<endl; 
                cout <<"\t\t\tBIENVENIDOS AL BANCO PICHINCHA" << endl;
                cout<< "\t---------------------------------------------------\n"<<endl; 
                int op = menu();
                while (op != 3){
                    switch (op){
                        case 1:{
                            meses(cantidad,mes);
                            cout << "-------------------------------------------"<<endl;
                            break;
                        }
                        case 2:{
                            buscar(cantidad);
                            cout << "-------------------------------------------"<<endl;
                            break;
                        }    
                    }
                    op = menu();
                }
                break;
            }
        }
        cout << endl;
        opcion = menu_principal();
    }
    if (opcion==4){exit (4);}
    system ("pause");
    return 0;
}

int opcion2(int longitud){

    cout<<" > INGRESE LA LONGITUD DE LA LISTA: ";
    cin>>longitud;
    while (longitud<=0){
        cout<<"\t\t [INGRESE UNA LONGITUD MAYOR A 0]"<<endl;
        cout<<" > INGRESE LA LONGITUD DE LA LISTA: ";
        cin>>longitud;
    }
    return longitud;
}

void Ordenar (int longitud,int lista[]){
    int max{0},min{0},aux{0},i{0},j{0};
    for ( i =0; i<longitud;i++){
        min = i;
        for ( j =i+1;j<longitud;j++){
            if (lista[j]< lista [min]){
                min = j;
            }
        }
        aux = lista[i];
        lista[i] = lista[min];
        lista [min] = aux;
    }
    ofstream llenarordenamiento;
    llenarordenamiento.open("ordenamiento.txt", ios::out | ios::app);
    llenarordenamiento<<"ORDENADO: ";
    cout<<"\t\tV E C T O R   O R D E N A D O"<<endl;
    for (int i =0;i<longitud;i++){
        cout<<"["<<lista[i]<<"] ";
        llenarordenamiento<<"["<<lista[i]<<"] ";
    }
    cout<<endl;
    llenarordenamiento<<endl;
    llenarordenamiento.close();
}

void llenar (int longitud, int lista[]){
    ofstream llenarordenamiento;
    llenarordenamiento.open("ordenamiento.txt", ios::out | ios::app);
    llenarordenamiento<<"ARREGLO INICIAL: ";
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
        llenarordenamiento<<"["<<lista[i]<<"] ";
    }
    llenarordenamiento<<endl;
    llenarordenamiento.close();
}

int menu_principal(){
    int op = -1;
    while (op < 0 || op >4){
        cout << "\t\tMENU PRINCIPAL" << endl;
        cout << "1. INTERCAMBIAR POSICIONES DE UN VECTOR"<<endl; 
        cout << "2. ORDENAMIENTO UN VECTOR"<<endl;
        cout << "3. CUENTA DE AHORROS VIRTUAL DEL BANCO PICHINCHA"<<endl;
        cout << "4. SALIR." << endl;
        cout<<"> Ingrese su opcion: ";
        cin>> op;
        if ((op < 1 || op >4)){
            cout << "\t\t[NO TENEMOS ESA OPCION]\n" << endl;
        }
    }
    return op;
}

int menu(){
    int op = -1;
    while (op < 0 || op >3){
        cout << "SELECIONE UNA OPCION DEL MENU." << endl;
        cout<< "1. Depositar dinero"<<endl; 
        cout<< "2. Consultar dinero"<<endl;
        cout<< "3. Salir"<<endl;
        cout<<" Ingrese su opcion: ";
        cin>> op;
        if ((op < 1 || op >3)){
            cout << "\t\t[NO TENEMOS ESA OPCION]\n" << endl;
        }
    }
    return op;
}

void meses(double Meses [Tam],string listameses[Tam]){
    int i =0;
    double cantidad = 0;
    ofstream llenarmeses;
    llenarmeses.open("cuenta.txt",ios :: out | ios :: app);
    for (i = 0; i < Tam; i++){
        cout << "> Ingrese la cantidad del mes "<< listameses[i] << ": ";
        cin >> cantidad;
        if (cantidad >= 0){
            Meses [i] = cantidad;
            llenarmeses<<"> "<<listameses[i]<<": "<<Meses[i]<<" ";
        }
        else{
            cout << "\t\t[No ingrese cantidades negativas]" << endl;
            i--;
        }
    }
    llenarmeses<<endl;
    llenarmeses.close();
}

void buscar(double Meses[Tam]){
    double numero = 0;
    bool band = false;
    ofstream llenarmeses;
    llenarmeses.open("cuenta.txt",ios :: out | ios :: app);
    cout<<" > Ingrese el numero que desee buscar: ";
    cin>>numero;
    llenarmeses<<"Cantidad a buscar: "<<numero;
    for (int i=0;i<Tam;i++){
        if (Meses[i] == numero){
            cout << "\tLa cantidad fue encontrada en la posicion ["<<i<<"]"<<endl;
            cout << "\t\t Correspondiente al mes de " << mes[i] << endl;
            llenarmeses<<" (> Encontrado, pos:"<<i<<" MES:"<<mes[i]<<")";
            band = true;
        }
    }
    if (band == false){
        cout<<"\t\t[VALOR NO ENCONTRADO]"<<endl;
        llenarmeses<<" (> No encontrado)"<<endl;
    }
    llenarmeses<<endl;
    llenarmeses.close();
}

void intercambio (){
    int num=6, aux=0,inter =0;
    int numeros[num];
    aux=num-1;

    cout<<"\t>>Ingrese 6 elementos de un arreglo: "<<endl;
    //Ingreso de datos
    for (int i=0; i<num; i++){
        cout<<"> Ingrese elemento "<<i+1<<" de un arreglo: ";
        cin>>numeros[i];
    }
    //Escritura del vector
    ofstream llenarintercambio;
    llenarintercambio.open("intercambiar.txt", ios::out | ios::app);
    llenarintercambio<<"ARREGLO INICIAL: ";
    cout<<endl<<"- ARREGLO: ";
    for (int i=0; i<num; i++){
        cout<<"["<<numeros[i]<<"] ";
        llenarintercambio<<"["<<numeros[i]<<"] ";
    }

    //Intercambio 
    for (int i=0; i<num/2; i++){
        inter=numeros[i];
        numeros[i]= numeros[aux];
        numeros[aux]=inter;
        aux--;
    }
    llenarintercambio<<endl;
    //Escritura del vector intercambiado
    llenarintercambio<<"INTERCAMBIADO: ";
    cout<<endl<<"- ARREGLO INTERCAMBIADO: ";
    for (int i=0; i<num; i++){
        cout<<"["<<numeros[i]<<"] ";
        llenarintercambio<<"["<<numeros[i]<<"] ";
    }
    cout<<"\n"<<endl;
    llenarintercambio<<endl;
    llenarintercambio.close();
    
}
