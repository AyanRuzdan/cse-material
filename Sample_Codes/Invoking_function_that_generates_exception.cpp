#include<iostream>
using namespace std;
void divide(int x,int y,int z)
{
cout<<"\n We are inside the function";
if((x-y)!=0)
{
int R=z/(x-y);
cout<<"\n Result="<<R;
}
else
{
throw(x-y);
}
}
int main()
{
try
{
cout<<"\n We are inside the try block";
divide(10,20,30);
divide(10,10,30);
}
catch(int i)
{
cout<<"\n Caught the exception:"<<i;
}
return 0;
}
