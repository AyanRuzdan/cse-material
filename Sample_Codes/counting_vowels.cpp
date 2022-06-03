#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	fstream obj1;
	char ch;
	int  count=0;
	obj1.open("vowels.txt",ios::in);
	if(!obj1)
	{
		cout<<"\n File could not be opened";
		exit(1);
	}
	ch=obj1.get();
	while(obj1)
	{
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
		{
		count++;
		}
		ch=obj1.get();
	}
	obj1.close();
	cout<<"\nTotal number of vowels are:"<<count;
	return 0;
}
