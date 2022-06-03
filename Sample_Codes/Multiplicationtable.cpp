#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	ifstream obj1;
	int num;
	obj1.open("abc.txt");
	if(!obj1)
	{
		cout<<"\n Input File could not be opened";
		exit(1);
	}
	obj1>>num;
	obj1.close();
	ofstream obj2;
	obj2.open("pqr.txt");
	if(!obj2)
	{
		cout<<"\n Output File could not be opened";
		exit(1);
	}
	for(int i=1;i<=10;i++)
	{
		obj2<<num<<"*"<<i<<"="<<num*i<<"\n";
	}
	return 0;
}
