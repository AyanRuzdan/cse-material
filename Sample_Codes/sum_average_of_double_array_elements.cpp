#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
double *arr,*sum,*avg;
int size;
sum=new double;
avg=new double;
cout<<"\n Enter the size of double array:";
cin>>size;
cout<<"\n Creating an array of size"<<size;
arr=new double[size];
if(arr==NULL||sum==NULL||avg==NULL)
{
cout<<"\n Problem in memory allocation";
exit(1);
}
cout<<"\nEnter array elements:";
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
for(int i=0;i<size;i++)
{
*sum=*sum+arr[i];
}
cout<<"\n Sum of elements of array is:"<<*sum;
*avg=*sum/size;
cout<<"\n Average of array elements is:"<<*avg;
delete []arr;
delete sum;
delete avg;
return 0;
}
