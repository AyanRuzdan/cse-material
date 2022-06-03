#include<iostream>
using namespace std;
class A
{
protected:
int x;
public:
void input()
{
	cout<<"\n Enter x:";
	cin>>x;
}
};
class B:public A
{
public:
void display()
{
cout<<"Square is:"<<x*x;
}
};
class C:public A
{
public:
void display()
{
int fact=1;
for(int i=1;i<=x;i++)
{
fact=fact*i;
}
cout<<"\n Factorial is:"<<fact;
}
};
int main()
{
B obj1;
obj1.input();
obj1.display();
C obj2;
obj2.input();
obj2.display();
return 0;
}
