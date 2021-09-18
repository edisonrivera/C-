#include <iostream>
using namespace std;

int main (){
    int num, *numx = NULL, **anumx = NULL;
    cout<<"DIGITE num: ";
    cin>>num;
    numx = &num;
    anumx = &numx;
    cout<<"NUMERO: [num]"<<num<<" [*numx]"<<*numx<<" [anumx]"<<**anumx<<endl;
    system("pause");
    return 0;
}