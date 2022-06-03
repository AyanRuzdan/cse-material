#include<iostream>
using namespace std;
class example
{
int x;
public:
void getdata(int a)
{
x=a;
}
void show()
{
cout<<"Value of x:"<<x<<"\n";
}
};
int main()
{
example *p=new example[2];
example *d=p;
example *flag=p;
int a;
for(int i=0;i<2;i++)
{
cout<<"\nEnter value:";
cin>>a;
p->getdata(a);
p++;
}
for(int i=0;i<2;i++)
{
cout<<"Value is:"<<"\n";
d->show();
d++;
}
delete[]flag;//Deallocation of memory
return 0;
}
