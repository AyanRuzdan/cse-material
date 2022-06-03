#include<iostream>
using namespace std;
class A
{
int x;
public:
void getdata()
{
cout<<"\n Enter value for x:"<<endl;
cin>>x;
}
void showdata()
{
cout<<"\n Entered value is:"<<x<<endl;
}
};
int main()
{
A obj1;
A *ptr;
ptr=&obj1;//Pointer to object
ptr->getdata();
ptr->showdata();
(*ptr).getdata();
(*ptr).showdata();
}
