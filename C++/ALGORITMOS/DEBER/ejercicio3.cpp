#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
void titulo (){
    cout<<setw(75)<<"|-^-|\t S U P E R M E R C A D O    A K I\t|-^-|\n";
    cout<<setw(85)<<"--------------------------------------------------------"<<endl;
    cout<<setw(80)<<"! BIENVENIDO A NUESTRO SOFTWARE DE INVENTARIO !"<<endl;
    cout<<setw(86)<<"--------------------------------------------------------\n"<<endl;
}

void sucursal(){
    string codigo, nombre, ciudad,telefono;
    ofstream sucursal;
    sucursal.open ("productos.txt", ios::out);
    cout<<setw(90)<<"---------------------- DATOS DE LA SUCURSAL ----------------------"<<endl;
    sucursal<<setw(90)<<"---------------------- DATOS DE LA SUCURSAL ----------------------"<<endl;
    cin.ignore ();
    cout<<setw(40)<<"> CODIGO: ";
    getline(cin,codigo);
    cout<<setw(40)<<"> NOMBRE: ";
    getline(cin,nombre);
    cout<<setw(40)<<"> CIUDAD: ";
    getline(cin,ciudad);
    cout<<setw(42)<<"> TELEFONO: ";
    getline(cin,telefono);
    sucursal<<setw(30)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(20)<<"CIUDAD"<<setw(20)<<"TELEFONO"<<endl;
    sucursal<<setw(30)<<codigo<<setw(20)<<nombre<<setw(20)<<ciudad<<setw(20)<<telefono<<endl;
    cout<<setw(90)<<"------------------------------------------------------------------\n"<<endl;
    sucursal<<setw(90)<<"------------------------------------------------------------------\n"<<endl;
    sucursal.close();
}

void ingresar (){
    int i= 0;
    string nombre, estado;
    int cantidad = 0,acucantidad=0;
    float precio = 0, subtotal=0,total=0;
    char letra;
    ofstream ingresardatos;
    ingresardatos.open("productos.txt",ios::out | ios:: app);
    ingresardatos<<setw(90)<<"---------------------- DATOS DEL PRODUCTO ----------------------"<<endl;
        ingresardatos<<setw(30)<<"NOMBRE"<<setw(20)<<"PRECIO"<<setw(20)<<"CANTIDAD"<<setw(20)<<"ESTADO"<<endl;
    do{
        cout<<setw(60)<<"------------- PRODUCTOS #"<<i+1<<"------------"<<endl;
        cout<<setw(45)<<"> NOMBRE: ";
        getline(cin,nombre);
        cout<<setw(45)<<"> PRECIO: ";
        cin>>precio;
        while (precio <= 0){
            cout<<setw(70)<<" ! INGRESE VALORES VALIDOS!"<<endl;
            cout<<setw(45)<<"> PRECIO: ";
            cin>>precio;
        }
        cout<<setw(47)<<"> CANTIDAD: ";
        cin>>cantidad;
        while (cantidad <= 0){
            cout<<setw(70)<<" ! INGRESE VALORES VALIDOS!"<<endl;
            cout<<setw(47)<<"> CANTIDAD: ";
            cin>>cantidad;
        }
        subtotal = (precio*cantidad);
        total += subtotal;
        acucantidad += cantidad;
        cin.ignore();
        cout<<setw(45)<<"> ESTADO: ";
        getline(cin,estado);
        cout<<setw(73)<<"--------------------------------------"<<endl;
        ingresardatos<<setw(30)<<nombre<<setw(20)<<precio<<setw(20)<<cantidad<<setw(20)<<estado<<endl;
        cout<<setw(70)<<" Para terminar ingrese [*] o continuar con [-]: ";
        cin>>letra;
        i++;
        cout<<endl;
        cin.ignore();
    } while (letra == '-');

    if (letra == '*'){
        ingresardatos<<"\n"<<right<<setw(80)<<"> CANTIDAD TOTAL DE PRODUCTOS: "<<acucantidad<<endl;
        ingresardatos<<right<<setw(80)<<"> CANTIDAD TOTAL DE PRODUCTOS INGRESADOS: "<<i<<endl;
        ingresardatos<<right<<setw(80)<<">  VALOR TOTAL DE LO PRODUCTOS INGRESADOS: $"<<total<<endl;
    }
    ingresardatos.close();
}