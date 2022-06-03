#include<iostream>
using namespace std;
class complex1
{
float x,y;
public:
complex1()
{
   x=0.0;
   y=0.0;
}
complex1(float real,float imag)
{
x=real;
y=imag;
}
complex1 operator+(complex1 obj1)
{
complex1 temp;
temp.x=x+obj1.x;
temp.y=y+obj1.y;
return temp;
}
void show_data()
{
cout<<x<<" +i"<<y<<"\n";
}
};
int main()
{
complex1 o1(2.7,3.6),o2(4.1,5.7),o3;
o3=o1+o2;
//o3=o1.operator+(o2);
o3.show_data();
}
