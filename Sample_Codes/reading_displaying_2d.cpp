#include<iostream>
using namespace std;
class two_D
{

int a[100][100];
int n,m;
public:
void getdata()
{
int i,j;
cout<<"\n Enter value of n(rows) and m(columns):"<<endl;
cin>>n>>m;
cout<<"\n Enter array elements:"<<endl;
   for(i=0; i<n; i++)
   {
   for(j=0; j<m; j++)
    {
       cin>>a[i][j];
    }
   }
}
void showdata()
{
   for(int i=0; i<n; i++)
   {
   for(int j=0; j<m; j++)
    {
       cout<<a[i][j]<<" ";
    }
    cout<<"\n";
   }	
}
};
int main()
{
	two_D obj1;
	obj1.getdata();
	obj1.showdata();
	return 0;
}
