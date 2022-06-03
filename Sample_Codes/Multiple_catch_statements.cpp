#include<iostream>
using namespace std;
void Test(int x)
{
try
{
if(x==1)
throw x; //int
else if(x==0)
throw 'x'; //char
else if (x== -1)
throw 1.0; //double
else if(x==2)
throw "Caught a string value";
cout<<"No suitable catch block found";
}
catch(char c) //catch 1
{ cout<<"\ncaught a character";}
catch(int m)
{ cout<<"\ncaught an integer";}
catch(double d)
{ cout<<"\ncaught a double";}
catch(const char*message)
{
cout<<"\n"<<message;
}
cout<<"\nEnd of try-catch system";
}
int main()
{
cout<<"\ntesting multiple catches";
cout<<"\nx==1";
Test(1);
cout<<"\nx==0";
Test(0);
cout<<"\nx==-1";
Test(-1);
cout<<"\nx==2";
Test(2);
cout<<"\n-----------------";
Test(10);
return 0; //and control passes to the next //statement after last catch
}
