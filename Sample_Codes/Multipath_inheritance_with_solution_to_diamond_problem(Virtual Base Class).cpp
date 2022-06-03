#include<iostream>
using namespace std;
class B
{
protected:
int x;
public:
void get_dataB()
{
cout<<"\n Enter value of x:";
cin>>x;
}
};
class DB1:virtual public B
{
protected:
int y;
public:
void get_dataDB1()
{
cout<<"\n Enter value of y:";
cin>>y;
}
};
class DB2: public virtual B
{
protected:
int z;
public:
void get_dataDB2()
{
cout<<"\n Enter value of z:";
cin>>z;
}
};
class D:public DB1,public DB2
{
public:
void sum()
{
int result;
result=x+y+z;
cout<<"\n Result is:"<<result;
}
};
int main()
{
D obj1;
obj1.get_dataB();
obj1.get_dataDB1();
obj1.get_dataDB2();
obj1.sum();
return 0;
}
