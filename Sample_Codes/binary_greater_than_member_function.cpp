#include<iostream>
using namespace std;
class greater1
{
int x;
public:
greater1(int a)
{
x=a;
}
bool operator>(greater1 o)
{
if(x>o.x)
return 1;
else
return 0;
}
friend bool operator!=(greater1,greater1);
};
bool operator!=(greater1 o1,greater1 o2)
{
 if(o1.x!=o2.x)
 {
     return 1;
 }
 else
 {
return 0;
 }
}
int main()
{
greater1 o1(3),o2(2);
if(o1>o2)
{
// or if(o1.operator>(o2))
//{
cout<<"\n o1 is greater than o2";
}
else
{
cout<<"\n o2 is greater than o1";
}
if(o1!=o2)
{
cout<<"\n o1 is not equal to o2";
}
else
{
    cout<<"\no1 and o2 are equal";
}
}
