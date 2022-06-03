#include<iostream>
using namespace std;
class array_searching
{
int a[100];
int n;
public:
void getdata()
{
cout<<"\n Enter value of n:"<<endl;
cin>>n;
cout<<"\n Enter array elements:"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
}
void linear_search()
{
int i,loc=-1,key;
cout<<"(Linear Search)Enter integer value to search in array:"<<endl;
cin>>key;
for(i=0;i<n;i++)
   {
    if (a[i]==key)
    {
     loc = i+1; // location of key is stored
     break;
    }
   }
   if(loc!= -1)
   {
     cout<<"Element found at location:"<<loc<<endl;
   }
   else
   {
     cout<<"Element not found";
   }

}
void binary_search2()
{
  int loc=-1,key,beg=0,last=n-1,mid;
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

}
};
int main()
{
    array_searching obj1;
    obj1.getdata();
    obj1.linear_search();
    obj1.binary_search2();
}
