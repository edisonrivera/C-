#include <iostream>
using namespace std;
#include <random>
#include <ctime>
void resultado ();
int main (){
    resultado();
    system ("pause");
    return 0;
}
void resultado (){
    int resultado =0 ;
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1,6);
    for (unsigned int contador =1;contador<=10;++contador){
        resultado = intAleatorio(motor)+intAleatorio(motor);
    }

}
