#include <iostream>
using namespace std;
const int Dias = 7;
typedef double tTemp [Dias]; // si suprimimos
double media (const tTemp temp); // const double temp[Dias]
int main (){
    tTemp temp; // double temp[Dias]
    for (int i =0;i<Dias;i++){
        cout<<"Temperatura del dia "<<i+1<<": ";
        cin>>temp[i];
    }
    
    for (int i =0;i<Dias;i++){
        cout<<"Temperatura del dia "<<i+1<<" es: "<<temp[i]<<endl;
    }
    cout<<" > La temperatura media es: "<<media(temp)<<endl;
    system ("pause");
    return 0;
}
double media(const tTemp temp){ //const double temp [Dias]
    double media,total=0;
    for (int i =0;i<Dias;i++){
        total = total + temp[i];
    }
    media = total/Dias;
    return media;
}
