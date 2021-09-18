#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
int menu_principal (int opcion);
// EJERCICIO 1
int exponencial (float x);
int factorial (int j);
float potencia (float x,int j);
// EJERCICIO 2
void segundo_despues (int h,int m,int s);
// EJERCICIO 3
void hipotenusa (double k,double y); 
// EJERCICIO 4
void cubos_numeros();
// EJERCICIO 5
int inverso(int num);
bool capicua(int resultado);
// EJERCICIO 6
void segundos_transcurridos (int h,int m,int s);
float x{0};
int op=-1;
int main(){
    while(op!=0){
        menu_principal(op); 
        switch (op){
            case 0:
                exit (0);
                break;
            case 1:{
                int n{0}, j{1};
                double res=0, total=0;
                cout<<"\t\t----------SERIES DE TAYLOR----------\n";
                cout<<" > Ingrese el valor x: ";
                cin>>x;
                exponencial(x);
                for ( j = 1;j<=10;j++){
                    res = potencia(x, j)/factorial(j);
                    total = total +res;
                }
                cout<<" > El resultado de sumar los 10 primeros elementos es: "<<total+1<<endl;
                break;
            }
            case 2:{
                float horas{0},minutos{0},segundos{0};
                    segundo_despues(horas,minutos,segundos);
                break;    
                } 
            case 3:{
                const double LADO1 =3.0,LADO2=4.0,LADO3=5.0,LADO4=12.0,LADO5=8.0,LADO6=15.0;
                cout<<"\t\t---------- HIPOTENUSAS ---------"<<endl;
                hipotenusa(LADO1,LADO2);
                hipotenusa(LADO3,LADO4);
                hipotenusa(LADO5,LADO6); 
                break;
            }
            case 4:{
                cubos_numeros();
                break;
            }
            case 5:{
                int numero{0};
                cout<<"\t\t---------- NUMEROS CAPICUAS --------"<<endl;
                cout<<" > Ingrese su numero: ";
                cin>>numero;
                while (numero>0){
                    inverso(numero);
                    capicua(numero);
                    cout<<" > Ingrese su numero: ";
                    cin>>numero;
                }
                break;
            }
            case 6:{
                float horas{0},minutos{0},segundos{0};
                segundos_transcurridos (horas,minutos,segundos);
                break;
            }
            default:
                break;
        }
        cout<<"\n";
    }
    system ("pause");
    return 0;
} 

int menu_principal (int opcion){
    cout<<"\t\t---------- MENU PRINCIPAL ----------\n";
    cout<<"1) SERIE DE TAYLOR"<<endl;
    cout<<"2) RELOJ DESPUES DE 1 SEGUNDO"<<endl;
    cout<<"3) HIPOTENUSA"<<endl;
    cout<<"4) CUBOS DE UN NUMERO"<<endl;
    cout<<"5) INVERSO DE UN NUMERO"<<endl;
    cout<<"6) CALCULAR TIEMPO"<<endl;
    cout<<"0) CERRAR"<<endl;
    cout<<" > Ingrese su opcion: ";
    cin>>op;
    while (op<0 or op>6){
        cout<<"\t\t[Ingrese solo las opciones presentadas]"<<endl;
        cout<<" > Ingrese su opcion: ";
        cin>>op;
    }
    cout<<"\n";
    return op;
}

int exponencial (float x){
    float ex=0;
    const float EULER = 2.718281;
    
    ex = (pow(EULER,x));
    cout<<" > El valor de la funcion exponencial es: "<<ex<<endl;
    return x;
}

int factorial(int j){
    int i =1,acu=1;
    for (i=1;i<=j;i++){
        acu = acu*i;
    }
    return acu;
}

float potencia (float x, int j){
    long long int res=0;
    int i{1};
    for (i=1;i<=j;i++){
        res = pow(x,i);
    }
    return res;
}

void segundo_despues (int h,int m,int s){
    const int SEG = 1;
        cout<<"\t\t----------RELOJ----------\n";
        cout<<" > Ingrese la hora: ";
        cin>>h;
        cin.ignore();
        cin>>m;
        cin.ignore();
        cin>>s;
        while((h>=24 || h<0) || (m>=60 || m<0) || (s>=60 || s <0)){
            cout<<"\t\t[El formato de la hora es incorrecta]"<<endl;
            cout<<" > Ingrese la hora: ";
            cin>>h;
            cin.ignore();
            cin>>m;
            cin.ignore();
            cin>>s;
        }
    s = s + SEG;
    if (s>=60){
        s =0;
        m = m+1;
        if (m>=60){          
            m =0;
            h = h+1;
            if (h>=24){              
                h =0;
            }
        }
    }
    cout<<" > La HORA despues de 1 segundo es: ";
    if (0==h || h<10){cout<<"0"<<h<<":";}
    else{cout<<h<<":";}
    if (0==m || m<10){cout<<"0"<<m<<":";}
    else{cout<<m<<":";}
    if (0==s || (s<10)){cout<<"0"<<s<<endl;}
    else{cout<<s<<endl;}
}

void hipotenusa (double k,double y){
    double hipotenusa{0};
    hipotenusa = pow((pow(k,2)+pow(y,2)),0.5);
    cout<<"\t\t -TRIANGULO HIPOTENUSA: "<<fixed<<setprecision(1)<<hipotenusa<<endl;
}

void cubos_numeros(){
    int entero{0},decimal{0},unidad{0},i=100,suma{0};
    cout<<"\t\t----------CUBOS DE LOS NUMEROS----------\n";
    for (i;i<1000;i++){
        entero = i/100;
        decimal = (i - (entero*100))/10;
        unidad = i-(entero*100)-(decimal*10);
        suma = pow(entero,3)+pow(decimal,3)+pow(unidad,3);
        if (suma == i){
            cout<<"\t\t -El numero "<<i<<" cumple con la condicion"<<endl;
        }
    }
}

int inverso(int num){
    int invert{0},res{0};
    if (num>0){
        while (num>0){
            res = num%10;
            num = num/10;
            invert =  (invert*10)+res;        
        }
    }
    else{
        exit(num<0);
    }
    return invert;
}

bool capicua(int resultado){
    bool condicion = true;
    if (resultado == inverso(resultado)){cout<<"\t\t[El numero es capicua]"<<endl;}
    else{cout<<"\t\t[El numero es no capicua]"<<endl;}
    return condicion;
}

void segundos_transcurridos (int h,int m,int s){
    int acu1=0,acu=0,o{0},u{0},segundos_totales = 0;
    cout<<"\t\t----------TIEMPO TRANSCURRIDO----------\n";
    cout<<" > Ingrese la hora: ";
    cin>>h;
    cin.ignore();
    cin>>m;
    cin.ignore();
    cin>>s;
    while((h>=24 or h<0) or (m>=60 or m<0) or (s>=60 or s<0)){
        cout<<"\t\t[El formato de la hora es incorrecta]"<<endl;
        cout<<" > Ingrese la hora: ";
        cin>>h;
        cin.ignore();
        cin>>m;
        cin.ignore();
        cin>>s;
    }
    if (h<12){
        acu = s+(m*60)+(h*3600);
        cout<<" > Cantidad de segundos: "<<acu<<endl;
    }
    else{
        h = (h-12);
        acu = s+(m*60)+(h*3600);
        cout<<" > Cantidad de segundos: "<<acu<<endl;
    }
    acu = 0;
    acu1 = 0;
    int acu2 = 0,acu3=0;
    cout<<"\n\t\t----------TIEMPO ENTRE 2 HORAS ----------\n";
    for (int i =0;i<2;i++){
        cout<<" > Ingrese la hora: ";
        cin>>h;
        cin.ignore();
        cin>>m;
        cin.ignore();
        cin>>s;    
        while((h>=24 or h<0) or (m>=60 or m<0) or (s>=60 or s<0)){
            cout<<"\t\t[El formato de la hora es incorrecta]"<<endl;
            cout<<" > Ingrese la hora: ";
            cin>>h;
            cin.ignore();
            cin>>m;
            cin.ignore();
            cin>>s;
        }      
        if (h<=12){
            acu3 = s+(m*60)+(h*3600);
            o +=1;
            acu2 = acu3-acu2;
        }
        else{
            u+=1;
            acu1 = s+(m*60)+(h*3600);
            acu= acu1-acu;
        }
        if (o==1 and u==1){segundos_totales = abs(acu-acu2);}
        if (o==2){segundos_totales = abs (acu2);}
        if (u==2){segundos_totales = abs (acu);}
    }
    cout<<" > Los segundos trancurridos entre las dos horas: "<<segundos_totales<<endl;
}