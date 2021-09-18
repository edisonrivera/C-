#include <iostream>
using namespace std;
#include <unistd.h>
#include <iomanip>
#include <cmath>
#include "calculos.h"
const int MAX = 100;
void sumar (){
    char signo = '+';
    float maxsuma[MAX], acu= 0;
    int i = 0;
    cout<<"\n"<<"----------------------------------------- INGRESE SUS NUMEROS A SUMAR --------------------------------------------------"<<endl;
    cout<<setw(85)<<"FORMATO EJEMPLO \"2+5=\"   '=' PARA TERMINAR Y LUEGO DAR ENTER"<<endl;
    cout<<"SUMA: ";
    while (signo != '='){
        cin>>maxsuma[i];
        cin>>signo;
        if (signo == '+' || '='){
            acu += maxsuma[i];
        }
        i++;
    }
    cout<<setw(60)<<" > EL RESULTADO ES: ["<<acu<<"]"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void restar (){
    char signo = '-';
    float maxresta[MAX], res= 0;
    int i = 0, cont = 0;
    cout<<"\n"<<"----------------------------------------- INGRESE SUS NUMEROS A RESTAR -------------------------------------------------"<<endl;
    cout<<setw(85)<<"FORMATO EJEMPLO \"2-5=\"   '=' PARA TERMINAR Y LUEGO DAR ENTER"<<endl;
    cout<<"RESTA: ";
    while (signo != '='){
        cin>>maxresta[i];
        cin>>signo;
        if (signo == '-' || '='){
            if (maxresta[0]<0){
                maxresta[0] = maxresta[0]*-1;
            }
            else{
                maxresta[0] = maxresta[0]*-1;
            }
            res -= maxresta[i];
        }
        i++;
    }
    cout<<setw(60)<<" > EL RESULTADO ES: ["<<res<<"]"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void multiplicacion(){
    char signo = '*';
    float maxmul[MAX];
    double multi= 1;
    int i = 0, cont = 0;
    cout<<"\n"<<"----------------------------------------- INGRESE SUS NUMEROS A MULTIPLICAR --------------------------------------------"<<endl;
    cout<<setw(85)<<"FORMATO EJEMPLO \"2*5=\"   '=' PARA TERMINAR Y LUEGO DAR ENTER"<<endl;
    cout<<"MULTIPLICACION: ";
    while (signo != '='){
        cin>>maxmul[i];
        cin>>signo;
        if (signo == '*' || '='){
            multi *= maxmul[i];
        }
        i++;
    }
    cout<<setw(60)<<" > EL RESULTADO ES: ["<<multi<<"]"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void division (){
    char signo = '/';
    float maxdiv[MAX], div = 0;
    int i = 0, cont = 0;
    cout<<"\n"<<"----------------------------------------- INGRESE SUS NUMEROS A DIVIDIR -----------------------------------------------"<<endl;
    cout<<setw(77)<<"FORMATO EJEMPLO \"2/5=\"   '=' PARA TERMINAR Y LUEGO DAR ENTER"<<endl;
    cout<<"DIVISION: ";
    while (signo != '='){
        cin>>maxdiv[i];
        cin>>signo;
        if (signo == '/' || '='){
            div = maxdiv[0]/maxdiv[1]; 
            cont++;
            if (i>1 && cont>=1){
                div /= maxdiv[i];
            }
        }
        i++;
    }
    cout<<setw(60)<<" > EL RESULTADO ES: ["<<div<<"]"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void potenciacion (){
    float base = 0, exponente = 0, resultado = 0;
    cout<<"\n"<<"----------------------------------------- INGRESE EL NUMERO A POTENCIAR -----------------------------------------------"<<endl;
    cout<<" > INGRESE LA BASE: ";
    cin>>base;
    cout<<" > INGRESE EL EXPONENTE: ";
    cin>>exponente;
    if (base == 0 && exponente == 0){
        cout<<setw(60)<<"[MATH ERROR]"<<endl;  
    }
    else{
        resultado = pow(base,exponente);
        cout<<setw(60)<<" > EL RESULTADO ES: ["<<resultado<<"]"<<endl;  
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void raiz (){
    float num = 0, res = 1;
    cout<<"\n"<<"------------------------------------------- INGRESE EL NUMERO DE LA RAIZ -----------------------------------------------"<<endl;
    cout<<" > INGRESE EL NUMERO: ";
    cin>>num;
    if (num<0){
        cout<<setw(60)<<"[MATH ERROR]"<<endl;  
    }
    else{
        res = sqrt(num);
        cout<<setw(60)<<" > EL RESULTADO ES: ["<<res<<"]"<<endl;   
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}

void factorial (){
    long int num = 0, res = 1;
    cout<<"\n"<<"----------------------------------------- INGRESE EL NUMERO DEL FACTORIAL ----------------------------------------------"<<endl;
    cout<<" > INGRESE EL NUMERO: ";
    cin>>num;
    if (num>0){
        for (int i = 1;i<=num;i++){
            res *= i; 
        }
    }
    else if (num == 0){res = 1;}
    else{
        for (int i = -1;i>=num;i--){
            res *= i; 
        }
    }
    cout<<setw(60)<<" > EL RESULTADO ES: ["<<res<<"]"<<endl; 
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    sleep(3);
    system("cls");
}