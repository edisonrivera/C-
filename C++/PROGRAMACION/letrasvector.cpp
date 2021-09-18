#include <iostream>
using namespace std;
const int V = 3;
const int SV = 10;
int incluido (const char vector1[], const char vector2[]);
int main (){
    char vector1[V] = {'a','b','k'};
    char vector2[SV] = {'a','r','k','t','z','s','a','h','b','x'};
    if (incluido (vector1,vector2) != 3){
        cout<<"ESTAN TODOS INCLUIDOS"<<endl;
    }
    else{
        cout<<"NO ESTAN TODOS INCLUIDOS"<<endl;
    }
    system ("pause");
    return 0;
}

int incluido (const char vector1[], const char vector2[]){
    int cont=0;
    for (int i = 0;i<V;i++){
        for (int j = 0;j<SV;j++){
            if (vector1[i] == vector2[j]){
                cont++;
            }
        }
    }
    return cont;
}

