#include<iostream>
using namespace std;
class A
{
public:
void show()
{
cout<<"\nIn Base Class A";
}
};
class B:public A
{
public:
void show()
{
cout<<"\nIn Derived Class B";
}
};
int main()
{
B obj1;
//obj1.show();
obj1.A::show();
return 0;
}
