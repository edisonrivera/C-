#include <iostream>
using namespace std;
#include <random>
#include <ctime>
void resultado ();
int main (){
    resultado();
    return 0;
}
void resultado (){
    int lista_suma [11] =  {0,0,0,0,0,0,0,0,0,0,0};
    int resultado = 0;
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1,6);;
    for (unsigned int contador = 0;contador<5000;contador++){
        resultado = intAleatorio(motor) + intAleatorio(motor);
        switch (resultado){
          case 2:
            lista_suma[0] ++;
            break;
          case 3:
            lista_suma[1] ++;
            break;
          case 4:
            lista_suma[2] ++;
            break;
          case 5:
            lista_suma[3] ++;
            break;
          case 6:
            lista_suma[4] ++;
            break;
          case 7:
            lista_suma[5] ++;
            break;
          case 8:
            lista_suma[6] ++;
            break;
          case 9:
            lista_suma[7] ++;
            break;
          case 10:
            lista_suma[8] ++;
            break;
          case 11:
            lista_suma[9] ++;
            break;
          case 12:
            lista_suma[10] ++; 
            break; 
        }
    }
    int contador = 2;
    for (int i = 0; i<11;i++){
      cout<<"Numero "<<"["<<contador<<"]: "<<lista_suma[i]<<endl;
      contador ++;
    }
}
