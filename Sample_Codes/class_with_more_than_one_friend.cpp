#include<iostream>
#include<conio.h>
using namespace std;
class sample
{
	int a;
	int b;
	public:
		void getdata()
		{
		    cout<<"Enter values for a and b:"<<endl;
		    cin>>a>>b;
		}
friend int multiply(sample s);
friend int subtract(sample s);
};
int multiply(sample s)
{
	return (s.a*s.b);
}
int subtract(sample s)
{
	return (s.a-s.b);
}
int main()
{
	sample X;
	X.getdata();
	cout<<"Multiply value for object X="<<multiply(X)<<"\n";
	cout<<"Subtraction value for object Y="<<subtract(X)<<"\n";
	getch();
	return 0;
}
