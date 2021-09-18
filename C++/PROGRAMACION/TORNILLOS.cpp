#include <iostream>
using namespace std;
int const MAX = 5;
void datos (float longitud[], float diametro[]);
void calcular (float longi[], float diame[]);
int main (){
    float longitudes [MAX];
    float diametros [MAX];
    datos(longitudes, diametros);
    calcular(longitudes,diametros);

    system ("pause");
    return 0;
}

void datos (float longitud[], float diametro[]){
    for(int i = 0;i<MAX;i++){
        cout<<"> LONGITUD ["<<i+1<<"]: ";
        cin>>longitud[i];
        while (longitud[i] <= 0){
            cout<<"! INGRESE NUMEROS VALIDOS !"<<endl;
            cout<<"> LONGITUD ["<<i+1<<"]: ";
            cin>>longitud[i];
        }
        cout<<"> DIAMETRO ["<<i+1<<"]: ";
        cin>>diametro[i];
        while(diametro[i] <= 0){
            cout<<"! INGRESE NUMEROS VALIDOS !"<<endl;
            cout<<"> DIAMETRO ["<<i+1<<"]: ";
            cin>>diametro[i];
        }
    }
}

void calcular (float longi[], float diame[]){
    float acu1 = 0, acu2 = 0;
    for (int i = 0;i<MAX;i++){
        acu1 += longi[i];
        acu2 += diame[i];
    }
    acu1 = acu1/MAX;
    acu2 = acu2/MAX;
    cout<<" --> MEDIA DE LONGITUDES: "<<acu1<<endl;
    cout<<" --> MEDIA DE DIAMETROS: "<<acu2<<endl;
}