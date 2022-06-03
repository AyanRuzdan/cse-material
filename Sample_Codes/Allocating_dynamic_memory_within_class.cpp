#include<iostream>
using namespace std;
class Array
{
int *arr;
int size;
public:
void get_data(int n)
{
size=n;
arr=new int[size];
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
}
int get_sum()
{
int sum=0;
for(int i=0;i<size;i++)
{
sum+=arr[i];
}
return sum;	
}
void display_data()
{
for(int i=0;i<size;i++)
{
cout<<"\t"<<arr[i];
}
cout<<"\n Sum of elements="<<get_sum();
}
~Array()
{
	delete []arr;
	cout<<"\nMemory deallocated";
}
};
int main()
{
Array a;
int n;
cout<<"\n Enter the number of elements:"<<endl;
cin>>n;
a.get_data(n);
a.display_data();
return 0;
}
