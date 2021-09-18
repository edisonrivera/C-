#include <iostream>
using namespace std;
#include <conio.h>
#include <cmath>
int exponencial (float x);
int factorial (int j);
float potencia (float x,int j);
float x;
int main(){
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
    cout<<" > El resultado de sumar los 10 primeros elementos es: "<<total+1;
    getch();
    return 0;
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