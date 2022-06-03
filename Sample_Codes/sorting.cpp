#include<iostream>
using namespace std;
int main()
{
int a[100];
int n,pass,hold,i;
cout<<"\n Enter value of n:"<<endl;
cin>>n;
cout<<"\n Enter array elements:"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
  
  cout<<"Data items in original order"<<endl;
   for (i=0;i<n;++i)
    {
      cout<<a[i]<<" ";
   } // end for
   // bubble sort
   // loop to control number of passes
   for (pass=1;pass<n;pass++ ) {
    // loop to control number of comparisons per pass
      for (i=0;i<n-1;++i) {
         // compare adjacent elements and swap them if first
         // element is greater than second element
         if (a[i]>a[i+1])
            {
            hold=a[i];
            a[i]=a[i+1];
            a[i+1]=hold;
            } // end if
      } // end inner for
   } // end outer for

   cout<<"\nData items in ascending order"<<endl;
   for (i=0;i<n;++i)
    {
      cout<<a[i]<<" ";
    } // end for
}
