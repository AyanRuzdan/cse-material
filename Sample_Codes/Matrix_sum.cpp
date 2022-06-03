#include<iostream>
using namespace std;
class matrix_sum
{
int a[50][50],b[50][50],c[50][50];
int n,m;
public:
void getdata()
{
int i,j;
cout<<"\n Enter value of n(rows) and m(columns):"<<endl;
cin>>n>>m;
cout<<"\n Enter array elements:"<<endl;
// Taking input using nested for loop
   cout<<"Enter elements of 1st matrix\n";
   for(i=0; i<n; ++i)
   {
   for(j=0; j<m; ++j)
    {
       cin>>a[i][j];
    }
   }
  // Taking input using nested for loop
   cout<<"Enter elements of 2nd matrix\n";
   for(i=0; i<n; ++i)
   {
    for(j=0; j<m; ++j)
    {
       cin>>b[i][j];
    }
   }
}
void sum()
{
   int i,j;
// adding corresponding elements of two arrays
   for(i=0; i<n; ++i)
   {
    for(j=0; j<m; ++j)
    {
       c[i][j] = a[i][j] + b[i][j];
    }
   }
}
void show()
{
    int i,j;
    // Displaying the sum
   cout<<"\nSum Of Matrix:\n";
   for(i=0; i<n; ++i)
   {
    for(j=0; j<m; ++j)
    {
       cout<<c[i][j]<<" ";
    }
          cout<<"\n";
    }
}
};
int main()
{
    matrix_sum obj1;
    obj1.getdata();
    obj1.sum();
    obj1.show();
}
