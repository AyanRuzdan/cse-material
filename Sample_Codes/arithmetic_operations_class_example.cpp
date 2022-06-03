#include<iostream>
using namespace std;
class arithmetic
{
int x,y;
public:
void getdata()
{
cout<<"Enter the value of x and y:"<<endl;
cin>>x>>y;
}
void sum()
{
int z;
z=x+y;
cout<<"Sum is:"<<z;
}
void divide()
{
int z;
z=x/y;
cout<<"Division is:"<<z;
}
void multiply()
{
int z;
z=x*y;
cout<<"Multiplication is:"<<z;
}
void subtract()
{
int z;
z=x-y;
cout<<"Subtraction result is:"<<z;
}
};
int main()
{
arithmetic obj1;
obj1.getdata();
obj1.sum();
obj1.subtract();
obj1.multiply();
obj1.divide();
}
