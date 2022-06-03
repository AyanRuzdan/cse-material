#include<iostream>
using namespace std;
int main()
{
int a[10],n;
cout<<"\n Enter value of n:"<<endl;
cin>>n;
int loc=-1,key,beg=0,last=n-1,mid;
cout<<"\n Enter array elements:"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"(Binary Search)Enter integer value to search in sorted array:"<<endl;
cin>>key;
while(beg<=last)
{
mid=(beg+last)/2; // determine middle element
if(a[mid]==key)
{
    loc=mid; //save the location of element.
    break;
}
    else if(a[mid]>key) //key less than middle element
    {
      last=mid-1;
    }
    else if(a[mid]<key) //key greater than middle element
    {
      beg=mid+1;
    } //end of if else
   } //end of while
   if(loc!=-1)
   {
     cout<<"\nElement found at location:"<<loc+1;
   }
   else
   {
     cout<<"\nElement not found";
   }
return 0;
}
