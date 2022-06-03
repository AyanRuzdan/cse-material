#include<iostream>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5};
	int i;
	cout<<"\n  Address of array is:"<<arr<<" "<<&arr[0]<<" "<<&arr<<endl;
	int *p;
	p=arr;
	cout<<"\n First value is:"<<*p<<endl;
	p=p+1;
	cout<<"\n Second value is:"<<*p<<endl;
	*p=45;
	p=p+2;
	*p=-2;
	cout<<"\n Modified array is:"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<"\n"<<arr[i];//We can also write i[arr]
	}
	p=arr;
	*(p+1)=0;
	*(p-1)=1;
	cout<<"\n Modified array is:"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<"\n"<<*(p+i);//We can also write *(i+arr)
	}
	return 0;
}
