#include <iostream>
using namespace std;
#include <fstream>
int ingresar ();
void mostrar (int veces);
int main (){
    int total = 0;
    total = ingresar();
    mostrar (total);
    system ("pause");
    return 0;
}

int ingresar (){
    int totalpeluches = 0;
    string nombre, color;
    int cantidad = 0;
    float precio = 0;
    char letra;
    ofstream ingresardatos;
    ingresardatos.open("inventario.txt",ios::out | ios:: app);
    do{
        cout<<"> NOMBRE DEL PELUCHE: ";
        getline(cin,nombre);
        cout<<"> PRECIO: ";
        cin>>precio;
        cout<<"> CANTIDAD: ";
        cin>>cantidad;
        cin.ignore();
        cout<<"> COLOR: ";
        getline(cin,color);
        totalpeluches ++;
        ingresardatos<<nombre<<" "<<precio<<" "<<cantidad<<" "<<color<<endl;
        cout<<" Para terminar ingrese [*] o continuar con [-]: ";
        cin>>letra;
        cout<<endl;
        cin.ignore();
    } while (letra == '-');
    ingresardatos.close();
    return totalpeluches;
}

void mostrar (int veces){
    string nombre,color;
    int cantidad = 0,acu =0;
    float precio = 0,total=0,sub=0;
    ifstream leer;
    leer.open("inventario.txt",ios::in);
    if (leer.fail()){
        cout<<"\t [E R R O R: Not found]"<<endl;
    }
    cout<<endl<<"\t---------- INVENTARIO ETAFASHION PELUCHES ---------"<<endl;
    cout<<"NOMBRE"<<"\tPRECIO"<<"\tCANTIDAD"<<"\tCOLOR"<<endl; 
    while (!leer.eof()){
        leer>>nombre>>precio>>cantidad>>color;
        if (!leer.eof()){
            cout<<nombre<<"\t"<<precio<<"\t"<<cantidad<<"\t"<<color<<endl;
            acu += cantidad;
            sub = precio*cantidad;
            total += sub;
        }
    }
    cout<<" > Numero TOTAL de peluches ingresados: "<<veces<<endl;
    cout<<" > Cantidad de peluches ADQUIRIDOS: "<<acu<<endl;
    cout<<" > VALOR TOTAL de los peluche: "<<total<<endl;
    cout<<endl;
    leer.close();
}