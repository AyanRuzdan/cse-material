#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
    ifstream obj;
    obj.open("input.txt");//Opening file for reading integer input
    if(!obj)
	{
		cout<<"\n File could not be opened for reading";
		exit(1);
	}
	obj>>n;
	obj.close();
	ofstream obj1;
	obj1.open("Table.txt");//Opening file for writing table for integer input
	if(!obj1)
	{
		cout<<"\n File could not be opened for writing";
		exit(1);
	}
	for(int i=1;i<=10;i++)
	{
		obj1<<n<<"X"<<i<<"="<<n*i;
		obj1<<"\n";
	}
	cout<<"\n Table written successfully";
	obj1.close();
}
