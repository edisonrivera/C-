#include <iostream>
using namespace std;
#include <fstream>
void menu (int opx);
void ingresar ();
void mostrar ();
int op{0};
string nombredelarchivo;
int main (){
    while (op !=3){
        menu(op);
        switch (op){
            case 1:
                ingresar();
            break;
            case 2:
                mostrar();
            break;

        }
    }
    if (op == 3){
        exit(3);
    }
    system ("pause");
    return 0;
}

void menu (int opx){
    cout<<"\t M E N U   D E  O P C I O N E S"<<endl;
    cout<<"1.- INGRESAR DATOS"<<endl;
    cout<<"2.- MOSTRAR DATOS"<<endl;
    cout<<"3.- SALIR"<<endl;
    cout<<"- Ingrese su opcion: ";
    cin>>op;
    while(op<1 || op>3){
        cout<<"\t[O P C I O N   I N C O R R E C T A]"<<endl;
        cout<<"- Ingrese su opcion: ";
        cin>>op;
    }
}

void ingresar (){
    string nombre, apellido, carrera;
    int edad{0};
    char letra;
    ofstream ingresardatos;
    cin.ignore();
    cout<<" > INGRESE EL NOMBRE DEL ARCHIVO: ";
    getline(cin,nombredelarchivo);
    ingresardatos.open(nombredelarchivo.c_str(),ios::out | ios:: app);
    do{
        cout<<"> Ingrese el NOMBRE: ";
        getline(cin,nombre);
        cout<<"> Ingrese el APELLIDO: ";
        getline(cin,apellido);
        cout<<"> Ingrese la CARRERA: ";
        getline(cin,carrera);
        cout<<"> Ingrese la EDAD: ";
        cin>>edad;
        ingresardatos<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
        cout<<" Desea ingresar mas contactos s/n: ";
        cin>>letra;
        cout<<endl;
        cin.ignore();
    } while (letra == 's');
    ingresardatos.close();
}

void mostrar (){
    string nombre,apellido,carrera;
    int i{1},edad{0};
    ifstream leer;
    leer.open(nombredelarchivo.c_str(),ios::in);
    if (leer.fail()){
        cout<<"\t [E R R O R: Not found]"<<endl;
    }
    while (!leer.eof()){
        leer>>nombre>>apellido>>carrera>>edad;
        if (!leer.eof()){ //USAR SOLO PARA LEER DATOS
            cout<<endl<<"\t---------- C O N T A C T O : "<<i<<"---------"<<endl;
            cout<<"\t> Nombre: "<<nombre<<endl;
            cout<<"\t> Apellido: "<<apellido<<endl;
            cout<<"\t> Carrera: "<<carrera<<endl;
            cout<<"\t> Edad: "<<edad<<endl;
            cout<<"\t---------------------------------------"<<endl;  
            i++;
        }
    }
    cout<<endl;
    leer.close();
}