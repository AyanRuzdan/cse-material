#include<iostream>
using namespace std;
int main()
{
	int num,*pnum,*pnum2,*pnum3;
	float x=2.0;
	pnum=&num;
	cout<<"\n Enter the number:";
	cin>>num;
	cout<<"The number that was entered is:"<<*pnum<<endl;
	cout<<"\n The address of number in memory is:"<<&num<<endl;
	cout<<"\n Address stored in pointer is:"<<pnum<<endl;//Address of num variable
	*pnum=4;
	cout<<"\n New value for variable num is:"<<num<<endl;
	pnum2=pnum;
	cout<<"\n Value of num is:"<<*pnum2<<endl;
	*pnum2=9;
	cout<<"\n New value for variable num is:"<<num<<endl;
	//pnum3=&x;//Invalid in C++ as integer pointer is storing address of floating variable
	return 0;
}
