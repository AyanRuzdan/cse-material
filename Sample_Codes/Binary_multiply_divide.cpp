#include<iostream>
using namespace std;
class binary
{
int x;
public:
binary()
{
   x=0;
}
binary(int num)
{
x=num;
}
binary operator*(binary obj1)
{
	binary temp;
	temp.x=x*obj1.x;
	return temp;
}
friend binary operator/(binary,binary);
void show_data()
{
cout<<x<<endl;
}
};
binary operator/(binary o1,binary o2)
{
binary temp;
temp.x=o1.x/o2.x;
return temp;
}
int main()
{
binary o1(4),o2(2),o3;
o3=o1*o2;
cout<<"\n Multiplication"<<endl;
o3.show_data();
binary o4,o5(6),o6(3);
cout<<"\n Division"<<endl;
o4=o5/o6;
o4.show_data();
return 0;
}
