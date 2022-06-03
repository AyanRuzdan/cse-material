#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	char data[100],output[100];
	cout<<"Enter data...";
	cin.getline(data,100);
	fstream obj1;
	obj1.open("Example1.txt",ios::out);
	if(!obj1)
	{
		cout<<"\n File could not be opened";
		exit(1);
	}
	obj1<<data;
	cout<<"\n Data written successfully";
	obj1.close();
	obj1.open("Example1.txt",ios::in);
	obj1.getline(output,100);
	cout<<"\n Data read successfully and it is as follows:"<<"\n";
	cout<<output;
	obj1.close();
	return 0;
}
