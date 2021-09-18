#include <iostream>
using namespace std;

int main(){
    int n =0, inicio = 0;
    cout<<"> INGRESE LA LONGITUD DE LA LISTA: ";
    cin>>n;
    int lista [n];
    int *nota = NULL;
    for (int i = 0;i<n; i++){
        nota = new int;
        cout<<"> INGRESE LOS VALORES ["<<i<<"]: ";
        cin>>*nota;
        lista[i] = *nota;
    }
    int aux = 0;
    for (int i = 0; i<n;i++){
        for (int j =0;j<n-1;j++){
            if (lista[j] > lista[j+1]){
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
    for (int i =0;i<n;i++){
        cout<<"["<<lista[i]<<"] ";
    }
    delete nota;
    system ("pause");
    return 0;
}
