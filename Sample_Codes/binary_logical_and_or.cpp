#include<iostream>
using namespace std;
class logical
{
int x;
public:
logical()
{
	x=0;
}
logical(int a)
{
x=a;
}
bool operator&&(logical o)
{
return (x&&o.x);
}
friend bool operator||(logical,logical);
};
bool operator||(logical o1,logical o2)
{
	return(o1.x||o2.x);
}
int main()
{
logical o1(2),o2(0);
int x=o1&&o2;
cout<<x<<endl;
int y=o1||o2;
cout<<endl<<y;
return 0;
}
