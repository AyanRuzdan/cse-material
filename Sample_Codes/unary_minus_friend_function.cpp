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
cout<<"\n Before overloading:";
cout<<x<<endl;
cout<<y<<endl;
cout<<z<<endl;
}
friend void operator(-)(Number);
};
void operator(-)(Number obj)
{
cout<<"\nAfter overloading:";
cout<<-obj.x<<endl;
cout<<-obj.y<<endl;
cout<<-obj.z;
}
int main()
{
Number N(7,8,9);
(-)N;
//operator-(N);
}
