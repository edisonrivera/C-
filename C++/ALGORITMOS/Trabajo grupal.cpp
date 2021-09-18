#include <iostream>
using namespace std;
const int Tam = 12;
string mes [Tam] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Nomviembre", "Diciembre"};
int menu_principal ();
int menu();
void meses(double Meses [Tam]);
void buscar(double Meses[Tam]);
void intercambio ();
void IngresarDatos (int &longitud, int lista []);
void Ordenar (int &longitud,int lista[]);
void imprimir (int &longitud,int lista []);
int longitud = 0;
int lista [100];
int main (){
    cout << "\t\tTRABAJO EN GRUPO" << endl;
    cout << "\tALGORITMOS Y ESTRUCTURA DE DATOS" << endl;
    int opcion = menu_principal();
    while (opcion != 4){
        switch (opcion){
            case 1:
                intercambio ();
                break;
            case 2:{
                IngresarDatos (longitud, lista);
                Ordenar (longitud, lista);
                imprimir ( longitud, lista);
                break;
            }   
            case 3:{
                double cantidad [Tam];
                cout<< "------------------------------------------------------------------\n"<<endl; 
                cout <<"\t\t\tBIENVENIDOS AL BANCO PICHINCHA" << endl;
                cout<< "------------------------------------------------------------------\n"<<endl; 
                int op = menu();
                while (op != 3){
                    switch (op){
                        case 1:{
                            meses(cantidad);
                            cout << "------------------------------------------------------------------"<<endl;
                            break;
                        }
                        case 2:{
                            buscar(cantidad);
                            cout << "------------------------------------------------------------------"<<endl;
                            break;
                        }    
                            op = menu();
                    }
                }
            break;
            }
        }
        opcion = menu_principal();
    }

    system ("pause");
    return 0;
}

void IngresarDatos (int &longitud, int lista []) {
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    while (longitud<= 0){
    cout<<"\t\t[Solo se admiten valores mayores a 0]"<<endl;
    cout<<"> Ingrese la longitud de la lista: ";
    cin>>longitud;
    }
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}

void Ordenar (int &longitud,int lista[]){
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
}

void imprimir (int &longitud,int lista []){
    for (int i = 0;i<longitud;i++){
        cout<<lista [i]<<" | ";
    }
    cout<<endl;
}

int menu_principal(){
    int op = -1;
    while (op < 0 || op >4){
        cout << "SELECIONE UNA OPCION DEL MENU." << endl;
        cout<< "1. INTERCAMBIAR POSICIONES DE UN VECTOR"<<endl; 
        cout<< "2. ORDENAMIENTO UN VECTOR"<<endl;
        cout<< "3. CUENTA DE AHORROS VIRTUAL DEL BANCO PICHINCHA"<<endl;
        cout<<" Ingrese su opcion: ";
        cin>> op;
        if ((op < 1 || op >4)){
            cout << "\t[No tenemos esa opcion]" << endl;
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
        cout<<" Ingrese su opcion: "<<endl;
        cin>> op;
        if ((op < 1 || op >3)){
            cout << "No tenemos esa opcion." << endl;
        }
    }
    return op;
}

void meses(double Meses [Tam]){
    double cantidad = 0;
    for (int i = 0; i < Tam; i++){
        cout << "Ingrese la cantidad de mes "<< i + 1 << ": ";
        cin >> cantidad;
        if (cantidad >= 0){
            Meses [i] = cantidad;
        }
        else{
            cout << "No ingrese cantidades negativas." << endl;
            i--;
        }
    }
}

void buscar(double Meses[Tam]){
    double numero = 0;
    bool band = false;
    cout<<" > Ingrese el numero que desee buscar: ";
    cin>>numero;
    for (int i=0;i<Tam;i++){
        if (Meses[i] == numero){
            cout << "\t\t La cantidad fue encontrada en la posicion ["<<i<<"]"<<endl;
            cout << "\t\t Correspondiente al mes de " << mes[i] << endl;
            band = true;
        }
    }
    if (band == false){
        cout<<"\tLa cantidad no ha sido ingresada."<<endl;
    }
}

void intercambio (){
    int num=6, aux;
    int numeros[num], temp[num];
    aux=num-1;

    cout<<"\t--> Ingrese 6 elementos de un arreglo: "<<endl;
    //Ingreso de datos
    for (int i=0; i<num; i++){
        cout<<"Ingrese elemento "<<i+1<<" de un arreglo: ";
        cin>>numeros[i];
    }

    //Escritura del vector
    cout<<"- ARREGLO: ";
    for (int i=0; i<num; i++){
        cout<<"["<<numeros[i]<<"] ";
    }
    //Intercambio 
    for (int i=0; i<num; i++){
        temp[aux]=numeros[i];
        aux--;
    }

    //Escritura del vector intercambiado
    cout<<endl<<"- ARREGLO INTERCAMBIADO: " ;
    for (int i=0; i<num; i++){
        cout<<"["<<temp[i]<<"] ";
    }
    cout<<"\n"<<endl;

}