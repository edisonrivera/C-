#include <iostream>
using namespace std;
#include <string>
void plurales (string palabra);
bool vocal (char vocal);
int main (){
    string a;
    plurales (a);
    cout<<endl;
    system ("pause");
    return 0;
}

bool vocal (char vocal) {
    return (vocal == 'a') || (vocal== 'e') ||(vocal == 'i') ||(vocal== 'o') ||(vocal == 'u');
}

void plurales (string palabra){
    string caso1 = "ces";
    string caso2 = "es";
    string caso3 = "s";
    cout<<"\t\t----------- PLURALES -------------"<<endl;
    cout<<" > Ingrese la palabra: ";
    getline (cin,palabra);
   if (palabra[palabra.size()-1] == 'z'){
        palabra.erase(palabra.size()-1,1);
        cout<<"PLURAL: "<<palabra+caso1;
    }

    if (vocal(palabra[palabra.size()-1])){
        cout<<"PLURAL: "<<palabra+caso3;
    }
    else{
        cout<<"PLURAL: "<<palabra+caso2; 
    } 
}
