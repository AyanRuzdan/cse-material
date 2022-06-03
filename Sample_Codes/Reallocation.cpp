#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int n,m;
cout<<"\n Enter the initial size:";
cin>>n;
int *arr=new int[n];
if(arr==NULL)
{
cout<<"\nMemory allocation failed";
exit(1);
}
cout<<"\nEnter the array elements:";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"\nThe array elements are:";
for(int i=0;i<n;i++)
{
cout<<" "<<arr[i];
}
cout<<"\n\n Memory requirement increases:";
cout<<"\nEnter new size(greater than n))";
cin>>m;
int *temp=new int[m];
if(temp==NULL)
{
cout<<"\n\n\nMemory Allocation failed";
exit(1);
}
cout<<"\n\n\n COPYING THE OLD ARRAY";
for(int i=0;i<n;i++)
{
temp[i]=arr[i];
}
delete []arr;
arr=temp;

cout<<"\n Enter new values:";
for(int i=n;i<m;i++)
{
cin>>arr[i];
}
cout<<"\n The array elements are:";
for(int i=0;i<m;i++)
{
cout<<" "<<arr[i];
}
delete [] arr;
return 0;
}
