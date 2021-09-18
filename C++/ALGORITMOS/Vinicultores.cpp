#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <fstream>
void titulo ();
string tipouva (string ti);
int tamaniouva (int ta);
double totalpagaruva (string ti,int ta,double p,int k);
double preciouva (double p);
int kilosuva (int k);
int main (){
    string tipox;
    int tamaniox=0,kx =0;
    double preciox=0;
    titulo();
    tipox = tipouva(tipox);
    tamaniox= tamaniouva(tamaniox);
    preciox= preciouva(preciox);
    kx = kilosuva (kx);
    cout<<"GANANCIA: "<<totalpagaruva(tipox,tamaniox,preciox,kx)<<endl;
    system("pause");
    return 0;
}

void titulo (){
    cout<<setw(70)<<"|-^-|\t V I N I C U L T O R E S   C . A\t|-^-|\n";
    cout<<setw(77)<<"------------------------------------------------------"<<endl;
    cout<<setw(75)<<"! P R O G R A M A   D E   C O N T A B I L I D A D !"<<endl;
    cout<<setw(77)<<"------------------------------------------------------"<<endl;
}

double preciouva(double p){
    ofstream ingresardatos("vinos.txt",ios::out|ios::app);
    cout<<" > Ingrese el precio: ";
    cin>>p;
    while (p < 0){
        cout<<setw(50)<<"[INGRESE VALORES MAYORES A 0]"<<endl;
        cout<<" > Ingrese el precio: ";
        cin>>p;
    }
    ingresardatos<<"PRECIO: "<<p<<" ";
    ingresardatos.close();
    return p;  
}

int kilosuva (int k){
    ofstream ingresardatos("vinos.txt",ios::out|ios::app);
    cout<<" > Ingrese la cantidad de kilos: ";
    cin>>k;
    while (k < 0){
        cout<<setw(50)<<"[INGRESE VALORES MAYORES A 0]"<<endl;
        cout<<" > Ingrese el precio: ";
        cin>>k;
    }
    ingresardatos<<"KILOS: "<<k<<" ";
    ingresardatos.close();
    return k;
}

string tipouva (string ti){
    ofstream ingresardatos("vinos.txt",ios::out|ios::app);
    cout<<" > Ingrese el tipo de uva (A/B): ";
    getline(cin,ti);
    while (ti != "A" && ti != "B"){
        cout<<setw(50)<<"[NO SE TIENE ESA OPCION]"<<endl;
        cout<<" > Ingrese el tipo de uva (A/B): ";
        getline(cin,ti);
    }
    ingresardatos<<"TIPO: "<<ti<<" ";
    ingresardatos.close();
    return ti;
}

int tamaniouva (int ta){
    ofstream ingresardatos("vinos.txt",ios::out|ios::app);
    cout<<" > Ingrese el tamanio de la uva (1/2): ";
    cin>>ta; 
    while (ta != 1 && ta != 2){
        cout<<setw(50)<<"[NO SE TIENE ESA OPCION]"<<endl;
        cout<<" > Ingrese el tamanio de la uva (1/2): ";
        cin>>ta;
    }
    ingresardatos<<"TAMANIO: "<<ta<<" ";
    ingresardatos.close();
    return ta;
}

double totalpagaruva (string ti,int ta,double p,int k){
    ofstream ingresardatos("vinos.txt",ios::out|ios::app);
    const float P1 = 0.2, P2 = 0.3, P3=0.5;
    float ga = 0;
    if (ti == "A"){
        if (ta == 1){
            p = p+P1;
        }
        else {
            if (ta == 2){
                p = p+P3;
            } 
        }
    }
    else{
        if (ti=="B"){
            if (ta == 1){
                p = p-P2;
            }
            else{
                if (ta == 2){
                    p = p-P3;
                }
            }
        } 
    }
    ga = p*k;
    ingresardatos<<"GANANCIA: "<<ga<<" "<<endl;
    ingresardatos.close();
    return ga;
}