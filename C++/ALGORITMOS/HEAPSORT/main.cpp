#include <iostream>
using namespace std;
#include <random>
#include <ctime>
#include "heapsort.h"
int main(){
    int arre [10]; 
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1,50);
    for (unsigned int contador =0;contador<10;++contador){
        arre[contador] = intAleatorio(motor);
    }
    heapsort (arre,10);
    for (int i =0;i<10-1;i++){
        cout<<"["<<arre[i]<<"] ";
    }
    cout<<endl;
    system("pause");
    return 0;
}