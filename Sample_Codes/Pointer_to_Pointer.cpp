#include<iostream>
using namespace std;
int main()
{
	int *ptr,**ptr1;
	int a=10;
	ptr=&a;
	cout<<*ptr<<endl;//It will display value of a
	ptr1=&ptr;
	cout<<**ptr1<<endl;//It will display value of a
	cout<<"Address of a is:"<<*ptr1<<" "<<ptr<<" "<<&a<<endl;//It will display address of a
	cout<<"Address of ptr is:"<<ptr1<<" "<<&ptr<<endl;//It will display address of ptr
	cout<<"Address of ptr1 is:"<<&ptr1;
	return 0;
}
