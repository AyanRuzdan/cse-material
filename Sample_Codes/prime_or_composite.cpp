#include<iostream>
using namespace std;
int prime(int,int);
int main()
{
	int status,n;
	cout<<"\nEnter number:";
	cin>>n;
	status=prime(n,2);
	if(status==0)
	cout<<"\nNumber is prime";
	else 
	cout<<"\nNumber is composite";
	return 0;
}
int prime(int num,int i)
{
	if(num%i==0)
	return 1;
	else if(i>num/2)
	return 0;
	else
	return prime(num,i+1);
}
