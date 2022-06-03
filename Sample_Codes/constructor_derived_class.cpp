#include <iostream>
using namespace std;
 
/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/

class Base1{
    int data;
    public:
        Base1(int i){
            data = i;
            cout<<"Base1 is called"<<endl;
        }

        void print1(){
            cout<<"Value of data in Base1 is "<<data<<endl;
        }
};

class Base2{
    int data;
    public:
        Base2(int i){
            data = i;
            cout<<"Base2 is called"<<endl;
        }

        void print2(){
            cout<<"Value of data in Base2 is "<<data<<endl;
        }
};

class Derived : public Base1, public Base2{
    int der1, der2;
    public:
        Derived(int a, int b, int c, int d) : Base1(a), Base2(b){
            der1 = c;
            der2 = d;
            cout<<"Derived is called"<<endl;
        }

        void print(){
            cout<<"Value of der1 : "<<der1<<endl;
            cout<<"Value of der2 : "<<der2<<endl;
        }

};

int main(){
    Derived test(1,2,3,4);
    test.print1();
    test.print2();
    test.print();
return 0;
}