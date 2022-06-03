#include<iostream>
using namespace std;
int main()
{
	int *ptr=NULL;
	int a=10;
	cout<<ptr<<endl;
	//cout<<*ptr;//---Not allowed(Dereferencing NULL pointer)
	ptr=&a;
	cout<<*ptr;//Now it is allowed, as NULL pointer has starting pointing somewhere
	return 0;
}
