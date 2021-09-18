#include <iostream>
using namespace std;
#include <fstream>
int opcion2(int longitud);
void sumar (int longitud, int lista[]);
void Ordenar (int longitud,int lista[]);
void llenar (int longitud, int lista[]);
void buscar (int longitud, int lista[]);
int main (){  
    int n =0;
    n = opcion2 (n);
    int arreglo [n];
    llenar (n,arreglo);
    sumar (n,arreglo);
    Ordenar (n,arreglo);
    buscar (n, arreglo);
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

void sumar (int longitud,int lista[]){
    int positivos = 0, negativos = 0;
    for (int i = 0;i<longitud;i++){
        if (lista[i]>=0){
            positivos += lista[i];
        }
        else{
            negativos += lista[i];
        }
    }
    cout<<" > Suma de los ELEMENTOS POSITIVOS: "<<positivos<<endl;
    cout<<" > Suma de los ELEMENTOS NEGATIVOS: "<<negativos<<endl;
}

void Ordenar (int longitud,int lista[]){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"\t\tL I S T A   I N G R E S A D A"<<endl;
    for (int i=0;i<longitud;i++){   
        cout<<"["<<lista[i]<<"] ";
    }
    cout<<endl<<"------------------------------------------------------"<<endl;
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
    ofstream ordenamiento;
    ordenamiento.open("ordenamiento.txt", ios::out | ios:: app);
    cout<<"\t\tL I S T A   O R D E N A D A"<<endl;
    for (int i =0;i<longitud;i++){
        cout<<"["<<lista[i]<<"] ";
        ordenamiento<<lista[i]<<" ";
    }
    ordenamiento<<endl;
    ordenamiento.close();
    cout<<endl<<"------------------------------------------------------"<<endl;
}

void llenar (int longitud, int lista[]){
    for (int i =0;i<longitud;i++){
        cout<<"> Ingrese el elemento en la Posicion ["<<i+1<<"]: ";
        cin>>lista[i];
    }
}

void buscar(int longitud, int lista[]){
    cout<<"\t\tB U S C A R   N U M E R O";
    int numero=0;
    bool band = false;
    ofstream busqueda;
    busqueda.open("busqueda.txt", ios::out | ios::app);
    cout<<endl<<" > Ingrese el numero que desee buscar: ";
    cin>>numero;
    busqueda<<numero<<endl;
    for (int j=0;j<longitud;++j){
        if (lista[j] == numero){
            cout<<" ----> N U M E R O  E N C O N T R A D O, posicion ["<<j<<"]"<<endl;
            band = true;
        }
    }
    if (band == false){
        cout<<"\tE L E M E N T O   N O   E N C O N T R A D O"<<endl;
    }
    busqueda<<band<<endl;
    
    cout<<"------------------------------------------------------"<<endl;
    busqueda.close();
}