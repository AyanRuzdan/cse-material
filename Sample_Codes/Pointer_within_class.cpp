#include<iostream>
using namespace std;
class Array
{
int *arr;
int size;
public:
void get_data(int n)
{
size=n;
arr=new int[size];
cout<<"\nEnter elements:";
for(int i=0;i<size;i++)
{
cin>>*(arr+i);
}
}
void add()
{
int sum=0;
for(int i=0;i<size;i++)
{
sum+=*(arr+i);
}
cout<<"\n Sum of elements="<<sum;
}
};
int main()
{
Array a;
int n;
cout<<"\n Enter the number of elements:"<<endl;
cin>>n;
a.get_data(n);
a.add();
return 0;
}
