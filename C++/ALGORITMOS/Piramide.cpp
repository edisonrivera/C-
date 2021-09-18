#include <iostream>
using namespace std;

#include <fstream>
string nombrearchivo; 
void escribirArchivo();

int main() 
{
  escribirArchivo();

}

void escribirArchivo()
{
  int niveles, aux;
  char letra;
  cout<<" \t\t G R A F I C A R   U N A    P I R A M I D E\n";
  ofstream archivoprueba;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin,nombrearchivo);
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do{
        cout<<" > Ingrese la CANTIDAD DE NIVELES: ";
        cin>>niveles;
        while (niveles<=0){
            cout<<"\t\t [SOLO SE ADMITEN NUMEROS MAYORES A 0]"<<endl;
            cout<<" > Ingrese la CANTIDAD DE NIVELES: ";
            cin>>niveles;
        }
        archivoprueba<<niveles<<endl;
        aux = niveles;
        cout<<"\n";
        for (int i =0;i<aux;i++){
            if (0 == i%2){
                for(int j =0;j<niveles;j++){
                    cout<<" * ";
                    archivoprueba<<" * ";
                }
            }
            else {
                for(int z =0;z<niveles;z++){
                    cout<<" - ";
                    archivoprueba<<" - ";
                }
            }
            archivoprueba<<endl;
            cout<<endl;
            niveles--;
        }
        cout<<" Desea graficar otra piramide (s/n): ";
        cin>>letra;
    }while (letra == 's');

  archivoprueba.close();

}