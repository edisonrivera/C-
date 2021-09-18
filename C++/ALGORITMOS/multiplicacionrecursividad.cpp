#include <iostream>
using namespace std;
#include <conio.h>
int multiplicacion (int a,int b);
int main (){
    int n1,n2;
    cout<<" > Ingrese el primer numero: ";
    cin>>n1;
    cout<<" > Ingrese el segundo numero: ";
    cin>>n2;
    cout<<" \t-El primer numero ingresado es: "<<n1<<endl;
    cout<<" \t-El segundo numero ingresado es: "<<n2<<endl;
    cout<<" > El resultado es: ["<<multiplicacion(n1,n2)<<"]"<<endl;
    getch();
    return 0;
}
int multiplicacion (int a,int b){
    if (b==1){
        return a;
    }
    if (b == 0){
        return 0;
    }
    if (b>0){
        return a+multiplicacion(a,b-1);
    }
    else{
        return -a+multiplicacion(a,b+1);
    }
    return (0);
}