#include <iostream>
using namespace std;
#include <conio.h>
int division (int a,int b);
int main (){
    int n1,n2;
    cout<<" > Ingrese el dividendo: ";
    cin>>n1;
    cout<<" > Ingrese el divisor: ";
    cin>>n2;
    if (n2 == 0){
        exit (0);
    }
    cout<<" \t-DIVIDENDO: "<<n1<<endl;
    cout<<" \t-DIVISOR: "<<n2<<endl;
    cout<<" > El resultado es: ["<<division(n1,n2)<<"]"<<endl;
    getch();
    return 0;
}

int division (int a,int b){
    if (a==b){return 1;}
    if (a<b){return 0;}
    if (a==0){return 0;}
    if (b==0){return 0;}
    if (a>b){return 1+ division(a-b,b);}
    return 0;
}