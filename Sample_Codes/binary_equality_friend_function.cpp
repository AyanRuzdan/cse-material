#include<iostream>
using namespace std;
class equality
{
int x,y;
public:
equality(int a,int b)
{
x=a;
y=b;
}
friend bool operator==(equality,equality);
};
bool operator==(equality o1,equality o2)
{
if((o1.x==o2.x) && (o1.y==o2.y))
return 1;
else
return 0;
}
int main()
{
equality o1(2,3),o2(3,3);
if(o1==o2)
{
// or if(operator==(o1,o2))
cout<<"\n Values of x and y for o1 and o2 are same";
}
else
{
cout<<"\n Values of x and y for o1 and o2 are not same";
}
}
