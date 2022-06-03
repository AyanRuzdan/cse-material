#include<iostream>
using namespace std;
int main()
{
   int a[3][3];
   int i,j;
   cout<<"\n Enter array elements:";
   for(i=0; i<3; i++)
   {
   for(j=0; j<3; j++)
    {
       cin>>a[i][j];
    }
   }
  cout<<"\n Entered elements are:"<<"\n";
   for(int i=0; i<3; i++)
   {
   for(int j=0; j<3; j++)
    {
       cout<<a[i][j]<<" ";
    }
    cout<<"\n";
   }	
}
