#include<iostream>
using namespace std;
int main()
{
	int x=10;
	char ch='A';
	void *gp;
	gp=&x;
	cout<<*(int*)gp<<endl;
	gp=&ch;
	cout<<*(char*)gp<<endl;
	return 0;
}
