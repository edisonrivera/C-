#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
void titulo ();
int main(){
    //titulo();
    float lista[10];
    for (int i =0;i<10;i++){
        cin>>lista[i];
    }
    system ("pause");
    return 0;
}
void titulo (){
    cout<<setw(70)<<"|-^-|\t E L E C T R O C A B L E S   C . A\t|-^-|\n";
    cout<<setw(77)<<"------------------------------------------------------"<<endl;
    cout<<setw(72)<<"! BIENVENIDO A NUESTRO SOFTWARE CONTABLE !"<<endl;
    cout<<setw(77)<<"------------------------------------------------------"<<endl;
}