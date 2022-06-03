#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int *arr1,*arr2,*arr3,sum=0;
int size1,size2,size3;
cout<<"\n Enter the size of first integer array:";
cin>>size1;
cout<<"\n Enter the size of second integer array:";
cin>>size2;
cout<<"\n Enter the size of third integer array:";
cin>>size3;
if(size1==size2&&size1==size3&&size2==size3)
{
arr1=new int[size1];
arr2=new int[size2];
arr3=new int[size3];
if(arr1==NULL||arr2==NULL||arr3==NULL)
{
cout<<"\n Problem in memory allocation";
exit(1);
}
cout<<"\nEnter first array elements:";
for(int i=0;i<size1;i++)
{
cin>>arr1[i];
}
cout<<"\nEnter second array elements:";
for(int i=0;i<size2;i++)
{
cin>>arr2[i];
}
for(int i=0;i<size3;i++)
{
arr3[i]=arr1[i]+arr2[i];
}
cout<<"\n Sum of elements of 2 arrays is:";
for(int i=0;i<size3;i++)
{
cout<<" "<<arr3[i];
}
delete []arr1;
delete []arr2;
delete []arr3;
}
else
{
cout<<"\n Invalid size";
exit(1);
}
return 0;
}
