#include <iostream>
using namespace std;
int factorial (int a);
int main (){
    int n1;
    cout<<" > Ingrese un numero: ";
    cin>> n1;
    cout<< " EL resultado es: ["<<factorial(n1)<<"]"<<endl;
    system("pause");
    return 0;
}
int factorial (int a){
    if (a ==1){
        return 1;
    }
    else{
        return a *factorial (a-1);
    }
}