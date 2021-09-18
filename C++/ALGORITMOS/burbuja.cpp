#include <iostream>
using namespace std;
int main (){
    int num [4]= {1,2,5,10},aux;
    for (int i =0;i<4;i++){ 
        for (int j=0;j<4-1;j++){
            if (num[j]>num[j+1]){
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        }
    }
    for (int i =0;i<4;i++){
        cout<<num[i]<<" | ";
    }
    system("pause");
    return 0;
}