#include<iostream>
using namespace std;
template <class T>
class abc
{
T *a;
int size;
public:
abc()
{
cout<<"\n Enter the size of array:";
cin>>size;
a=new T[size];
cout<<"\n Enter the array values:";
for(int i=0;i<size;i++)
cin>>a[i];
}
T sum1()
{
T sum=0;
for(int i=0;i<size;i++)
sum=sum+a[i];
return sum;
}
};
int main()
{
abc<int>obj1;
cout<<"\n Sum of integer array elements are:"<<obj1.sum1();
abc<float>obj2;
cout<<"\n Sum of float array elements are:"<<obj2.sum1();
return 0;
}
