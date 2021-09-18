#include <iostream>
using namespace std;
int main (){
    int i;
    int *p;
    p =  new int;
    cin>>*p;
    cout<<*p;
    delete p;
    system ("pause");
    return 0;
}
