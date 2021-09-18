#include <iostream>
using namespace std;
#include <fstream>
void rellenar ();
void leer();
int main(){
    rellenar();
    leer ();
    system ("pause");
    return 0;   
}

void rellenar (){
    char opcion;
    string nombre,direccion;
    int edad{0};
    ofstream llenar;
    llenar.open("C:/Users/pc/Documents/testing.txt",ios :: out | ios::app);  //abrir archivo //nombreArchivo.c_str()  
    if (!llenar.fail()){
        cout<<"\t A R C H I V O   N O    C R E A D O"<<endl;
    }
    cout<<"\t\t |-^-| L I S T A   D E   C O N T A C T O S |-^-|\n"<<endl;
    do{
        cout<<" -INGRESE EL NOMBRE: ";
        getline(cin,nombre);
        cout<<" -INGRESE LA EDAD: ";
        cin>>edad;
        cin.ignore();
        cout<<" -INGRESE LA DIRECCION: ";
        getline(cin,direccion);
        llenar<<nombre<<"  "<<edad<<" "<<direccion<<endl;  
        cout<<" Desea ingresar mas contactos s/n: ";
        cin>>opcion;

        cin.ignore();
        cout<<endl;
    } while (opcion == 's');

    llenar.close(); // IMPORTANTE CERRAR SIEMPRE
}

void leer(){
    string nombre,direccion;
    int i{1},edad{0};
    ifstream leer;
    leer.open("C:/Users/pc/Documents/testing.txt",ios::in);
    if (leer.fail()){
        cout<<"\t A R C H I V O   N O    E N C O N T R A D O"<<endl;
    }
    while (!leer.eof()){
        leer>>nombre>>edad>>direccion;
        if (!leer.eof()){
            cout<<endl<<"---------- C O N T A C T O : "<<i<<"---------"<<endl;
            cout<<"> Nombre del contacto: "<<nombre<<endl;
            cout<<"> Edad: "<<edad<<endl;
            cout<<"> Direccion: "<<direccion<<endl;
            cout<<"---------------------------------------"<<endl;  
            i++;
               
        }
    }
    leer.close();
}