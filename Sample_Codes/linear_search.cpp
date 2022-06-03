#include<iostream>
using namespace std;
int main()
{
int a[10];
int i,n,loc=-1,key;
cout<<"\n Enter value of n:"<<endl;
cin>>n;
cout<<"\n Enter array elements:"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
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
