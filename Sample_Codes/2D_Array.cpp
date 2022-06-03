#include<iostream>
using namespace std;
int main()
{
	int  a[2][2]={{2,3},{4,5}};
	int a1[2][2]={2,3,4,5};
	int a2[2][2]={{2},{1,5}};
	int a3[2][2]={1,2};
	int a4[2][2]={0};
	int a5[][2]={1,2,3,4};
	int a6[2][2];
	int i,j;
	cout<<"\n Elements of a array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>a6[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n Elements of a1 array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
	      cout<<a1[i][j]<<" ";
		}
		cout<<"\n";
    }
    cout<<"\n Elements of a2 array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		 cout<<a2[i][j]<<" ";
		}
		cout<<"\n";
    }
    cout<<"\n Elements of a3 array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		cout<<a3[i][j]<<" ";
		}
		cout<<"\n";
    }
    cout<<"\n Elements of a4 array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		cout<<a4[i][j]<<" ";
		}
		cout<<"\n";
    }
    cout<<"\n Elements of a5 array are:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		cout<<a5[i][j]<<" ";
		}
		cout<<"\n";
    }
}
