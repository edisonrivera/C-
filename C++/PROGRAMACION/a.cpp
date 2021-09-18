#include <iostream>
using namespace std;
#include <string.h>
int calcular ();
int main(){
    cout<<"El resultado es: "<< calcular ()<<endl;
    system ("pause");
    return 0;
}
int calcular (){
    string buscar = "c";
    for (int i = 0;i<buscar.length();i++){
        buscar[i] = tolower(buscar[i]); 
    }
    string texto =  "abcdefgci";
    for (int i = 0;i<texto.length();i++){
        texto[i] = tolower(texto[i]); 
    }
    if (texto.length() > 217483647 || texto.length() < 1){
        cout<<"[IMPOSIBLE DE CALCULAR]"<<endl;
    }
    if (buscar.length() < 1 || buscar.length()>texto.length()){
        cout<<"[IMPOSIBLE DE CALCULAR]"<<endl;
    }
    int resultado = 0;
    if (buscar.length()==1){
        resultado = texto.rfind(buscar);
    }
    else{
        resultado = texto.length()-(texto.rfind(buscar)+buscar.length());
    }
    return resultado;
}