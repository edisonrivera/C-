#include <iostream>
using namespace std;
typedef struct{
    int codigo;
    string nombre;
}tRegistro;
const int MAX = 5;
int main (){
    const int *cteMAX = &MAX;
    typedef int *tIntPtr;
    int num, *dir_num = NULL;
    tRegistro registro;
    tRegistro *puntero= &registro;
    registro.codigo = 123;
    cout<<"CODIGO (*). : "<<(*puntero).codigo<<endl; //RECORDAR LOS ();
    cout<<"CODIGO -> : "<<puntero->codigo<<endl;
    cout<<"PUNTERO CONST: "<<cteMAX<<endl;
    int entero = 1;
    tIntPtr puntInt = &entero;
    cout<<" > Digite un numero: ";
    cin>>num;
    dir_num = &num;
    cout<<" > \"FORMA NORMAL\" El numero ["<<*dir_num<<"] tiene la posicion: "<<dir_num<<endl;
    cout<<" > Usado con \"TYPEDEF\": "<<*puntInt<<endl;

    system("pause");
    return 0;
}