#include <iostream>
using namespace std;
const int MAX = 10;
typedef int tVector[MAX];
void mostrarvector (tVector vector1);
void desplazar (tVector vector1);
int mayornum (tVector vector1);
void repetidos (tVector vector1);
int main (){
    tVector vector1;
    for (int i = 0;i<MAX;i++){
        vector1[i] = rand() % 10;
    }
    cout<<"\tVECTOR ORIGINAL"<<endl;
    mostrarvector (vector1);
    desplazar(vector1);
    cout<<"MAYOR: "<<mayornum (vector1)<<endl;
    repetidos(vector1);
    cout<<endl;
    system ("pause");
    return 0;
}

void mostrarvector (tVector vector1){
    for (int i = 0;i<MAX;i++){
        cout<<"["<<vector1[i]<<"]";
    }
    cout<<endl;
}

void desplazar (tVector vector1){
    int aux = 0;
    aux = vector1[MAX-1];
    for (int i = MAX-1;i>0;i--){
        vector1[i] = vector1[i-1];
    }
    vector1[0] = aux;
    cout<<"\tVECTOR DESPLAZADO"<<endl;
    mostrarvector(vector1);
}

int mayornum (tVector vector1){
    int mayor = 0;
    mayor = vector1[0];
    for (int i = 0;i<MAX;i++){
        if (mayor < vector1[i]){
            mayor = vector1[i];
        }
    }
    return mayor;
}

void repetidos (tVector vector1){
    cout<<"\tELEMENTOS REPETIDOS"<<endl;
    for (int i = 0;i<MAX;i++){    
        for (int j = i+1;j<MAX;j++){
            if (vector1[i] == vector1[j]){
                cout<<"El numero ["<<vector1[i]<<"] esta repetido en la posicion ["<<j<<"]"<<endl;
            }
        }
    }
}
