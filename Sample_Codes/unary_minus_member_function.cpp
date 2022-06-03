#include<iostream>
using namespace std;
class Number
{
private:
int x,y,z;
public:
Number(int n,int n1,int n2)
{
x=n;
y=n1;
z=n2;
}
void operator-()
{
x=-x;
y=-y;
z=-z;
}
void show_data()
{
cout<<"\n x="<<x<<"\n";
cout<<"\n y="<<y<<"\n";
cout<<"\n z="<<z<<"\n";
}
};
int main()
{
Number N(7,8,9);
N.show_data();
-N;//Indirect way of calling operator member function
//N.operator-();//Direct way of calling operator member function
N.show_data();
}
