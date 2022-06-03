#include<iostream>
using namespace std;
class binary
{
int x,y;
public:
binary()
{
   x=0;
   y=0;
}
binary(int x1,int y1)
{
x=x1;
y=y1;
}
binary operator+(binary obj1)
{
binary temp;
temp.x=x+obj1.x;
temp.y=y+obj1.y;
return temp;
}
void show_data()
{
cout<<x<<" "<<y<<"\n";
}
};
int main()
{
binary o1(1,2),o2(3,4),o3;
o3=o1+o2;
//o3=o1.operator+(o2);
o3.show_data();
}
