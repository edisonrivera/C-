#include <iostream>
using namespace std;
#include <fstream>
ofstream archivox;
#define tam 50
int const Max = 100;

int menu(){
    int op = -1;
    while (op < 1 || op >5){
        cout<<"\t\t\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl<<endl; 
        cout << "\t\tSELECIONE UNA OPCION DEL MENU." << endl;
        cout << "\t\t1. Realizar transacciones"<<endl; 
        cout << "\t\t2. Mostrar transacciones"<<endl;
        cout << "\t\t3. Ordenar transacciones"<<endl;
        cout << "\t\t4. Buscar transaccion"<<endl;
        cout << "\t\t5. Salir"<<endl;
        cout << "\t\t> Ingrese su opcion: ";
        cin >> op;
        if ((op < 1 || op >5)){
            cout << "No tenemos esa opcion." << endl;
        }
    }
    return op;
}

void ingresar(double a[],int n)
{
    system("cls");
    cout<<"\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl; 
    for(int i=0;i<n;i++)
    {
        cout<<"Ingresa la transaccion: "<<i+1<<": ";
        cin>>a[i];
        while (a[i]<0){
            cout<<"Ingresa la transaccion: "<<i+1<<": ";
            cin>>a[i];
            
            if (a[i]<0){
                cout<<"Ingrese los valores mayores a cero"<<endl;
            }
        }
    }
    
}

void guardar (double a[], int n){
    archivox.open("ejercicio2.txt",ios::out | ios::app);
        for (int i=0; i<n;i++)
        {
            archivox<<"["<<a[i]<<"]"; 
        }
        archivox<<endl;
    archivox.close();
        
}

void imprimir(double a[],int n)
{
    system("cls");
    cout<<"\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl; 
    cout<<"Transacciones: ";
    for (int i=0; i<n;i++)
    {
        cout<<"["<<a[i]<<"]"; 
    }
    cout<<endl<<endl;
}

void fusionar (double a[],int ini,int fi,int medio){
    double temp[fi-ini+1];
    int i,j,k =0;
    i = ini;
    j = medio +1;
    while(i<=medio && j <=fi){
        if (a[i] < a[j]){
            temp [k] =  a[i];
            k++;
            i++;
        }
        else{
            temp [k] = a[j];
            k++;
            j++;
        }
    }    
    while (i<=medio){
        temp[k] = a[i];
        i++;
        k++;

    }
    while (j<=fi){
        temp [k] = a[j];
        k++;
        j++;
    }
    for (i=ini; i<=fi;i++){
        a[i] = temp[i-ini];
    }
    
}

void dividir (double a[], int inicial, int longitud){
    int mitad;
    if (inicial<longitud){
        mitad = (inicial+longitud)/2;
        dividir (a,inicial,mitad);
        dividir (a,mitad+1,longitud);
        fusionar(a,inicial,longitud,mitad);
    }
    imprimir(a, longitud);
    
}

void buscar(int &longitud, double a[]){
    archivox.open("ejercicio2.txt",ios::out | ios::app);
    double numero=0;
    bool band = false;
    cout<<"\t - BIENVENIDO A 'BANCO DEL PACIFICO' -"<<endl; 
    cout<<" > Ingrese el numero que desee buscar: ";
    cin>>numero;
    archivox<<"Trasaccion a buscar: "<<numero<<endl;
    for (int i=0;i<longitud;i++){
        if (a[i] == numero){
            cout<<"\t\t -----> N U M E R O  E N C O N T R A D O, posicion ["<<i<<"]"<<endl;
            archivox<<"Encontrado en la posicion: "<<i<<endl;
            band = true;
        }
    }
    if (band == false){
        cout<<"\tN O  S E   E N C O N T R O "<<endl;
        archivox<<"No encontrado"<<endl;
    }
    archivox.close();
}