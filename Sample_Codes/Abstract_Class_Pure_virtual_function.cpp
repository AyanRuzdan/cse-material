#include<iostream>
using namespace std;
class sample
{
public:
virtual void example()=0;
void show()
{
cout<<"\nThis is sample abstract class";
}
};
class derived1:public sample
{
public:
void example()
{
cout<<"C++";
}
};
class derived2:public sample
{
public:
void example()
{
cout<<"\nC";
}
};
int main()
{
sample *ptr;//Base pointer
sample obj;//Compile time error(Creating object of abstract class)
derived1 obj1;
derived2 obj2;
ptr=&obj1;//Currently pointer is pointing towards derived1
ptr->example();
ptr->show();
ptr=&obj2;//Currently pointer is pointing towards derived2
ptr->example();
ptr->show();
return 0;
}
