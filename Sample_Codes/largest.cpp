#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	int x,y,z;
	int x1,y1,z1;
	cout<<"\n Enter three integers:";
	cin>>x>>y>>z;
	ofstream obj1("input.txt");
	if(!obj1)
	{
		cout<<"\n File could not be opened for writing input";
		exit(1);
	}
	obj1<<x<<" "<<y<<" "<<z;
	obj1.close();
	ifstream obj2("input.txt");
	if(!obj1)
	{
		cout<<"\n File could not be opened for writing input";
		exit(1);
	}
	obj2>>x1;
	obj2>>y1;
	obj2>>z1;
	obj2.close();
	ofstream obj3("output.txt");
	if(!obj3)
	{
		cout<<"\n File could not be opened for writing Output";
		exit(1);
	}
	if(x1>y1&&x1>z1)
	{
		obj3<<x1;
	}
	else if(y1>x1 && y1>z1)
	{
		obj3<<y1;
	}
	else
	{
		obj3<<z1;
	}
	obj3.close();
	return 0;
}
