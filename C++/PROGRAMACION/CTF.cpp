#include <iostream>
using namespace std;
int main (){
    int num = 0,inicio = 0,cont = 1, ver = 0;
    cout<<" > Ingrese el numero: ";
    cin>>num;
    if (num%2 == 0){num++;}
    ver = num /4;
    int final = num-1;
    char matriz [num][num];
    for (int i = 0; i<num;i++){
        for (int j = 0;j<num;j++){
            if (cont == j && inicio>i &&  inicio>j && i<final && j<final){
                matriz [i][j] = ' ';
                cont++;
            }
            else{matriz[i][j] = '*';} 
            inicio++; 
        }
        
    }

    for (int i = 0; i<num;i++){
        for (int j =0;j<num;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    system ("pause");
    return 0;
}
    
