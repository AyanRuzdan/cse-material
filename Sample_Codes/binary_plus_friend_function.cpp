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
friend binary operator+(binary,binary);
void show_data()
{
cout<<x<<" "<<y<<"\n";
}
};
binary operator+(binary o1,binary o2)
{
binary temp;
temp.x=o1.x+o2.x;
temp.y=o1.y+o2.y;
return temp;
}
int main()
{
binary o1(1,2),o2(3,4),o3;
o3=o1+o2;
//o3=operator+(o1,o2);
o3.show_data();
}
