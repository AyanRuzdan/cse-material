#include<iostream>
using namespace std;
void divide(double x, double y)
{
cout<<"\nInside function";
try
{
if(y==0.0)
throw y; //Throwing double
else
cout<<"\nDivision="<< x/y;
}
catch(double) // Catch a double
{
cout<<"\nCaught double inside function:";
throw; // Rethrowing double
}
cout<<"\nEnd of function";
}
int main()
{
cout<<"\nInside main";
try
{
divide(10.5,2.0);
divide(20.0,0.0);
}
catch(double)
{
cout<<"\nCaught double inside main";
}
cout<<"\nEnd of main";
return 0;
}
