#include<iostream>
using namespace std;
class equality
{
int x,y;
public:
equality()
{
	x=0;
	y=0;
}
equality(int a,int b)
{
x=a;
y=b;
}
bool operator==(equality o)
{
if((x==o.x) && (y==o.y))
return 1;
else
return 0;
}
};
int main()
{
equality o1(3,3),o2(3,6);
if(o1==o2)
{
// or if(o1.operator==(o2))
//{
cout<<"\n Values of x and y for o1 and o2 are same";
}
else
{
cout<<"\n Values of x and y for o1 and o2 are not same";
}
}
