#include <iostream>
using namespace std;
 
class Base1{
    public:
    int base1int;
};

class Base2{
    public:
    int base2int;
};

class Derived : public Base1, public Base2{
    public:
     void result();
};
void Derived :: result(){
    cout<<"int1 : "<<base1int<<endl;
    cout<<"int2 : "<<base2int<<endl;
    cout<<base1int+base2int<<endl;
}

int main(){
    Derived der;
    der.base1int = 5;
    der.base2int = 4;

    der.result();
    
 
return 0;
}