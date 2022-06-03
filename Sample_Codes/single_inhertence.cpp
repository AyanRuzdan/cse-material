#include <iostream>
using namespace std;
 

class Base{     //Base Class
    int data1;    //private members do not inherit
    public:
        int data2;
        void setdata();
        int getdata1();
        int getdata2();
};

void Base :: setdata(){
    data1 = 10;
    data2 = 20;
}

int Base :: getdata1(){
    return data1;
}

int Base :: getdata2(){
    return data2;
}

class Derived : public Base
{
private:
    int data3;  
public:
    int process();
    void display();
};

int Derived :: process(){
    data3 = data2 * getdata1();    //can acess data2 as member but cannot access data1 as member as it is provate in Base class
    return data3;
}

void Derived :: display(){
    cout<<"Value of data1 = "<<getdata1()<<endl;  //data1 can be accessed using a public method defined in BAse class
    cout<<"Value of data2 = "<<data2<<endl;
    cout<<"Value of data3 = "<<data3<<endl;
}


int main(){
    Derived der;
    der.setdata();
    der.process();
    der.display();
 
 
return 0;
}