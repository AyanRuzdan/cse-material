#include<iostream>
using namespace std;
class X
{
protected:
int a;
public:
void getdataX()
{
cout<<"\n Enter value of a:";
cin>>a;
}
};
class Y:public X
{
protected:
int b;
public:
void getdataY()
{
cout<<"\n Enter value of b:";
cin>>b;
}
};
class Z:public Y
{
private:
int c,result;
public:
void getdataZ()
{
cout<<"\n Enter value of c:";
cin>>c;
}
void sum()
{
result=a+b+c;
cout<<"\n Final result is:"<<result;
}
};
int main()
{
Z obj1;
obj1.getdataX();
obj1.getdataY();
obj1.getdataZ();
obj1.sum();
return 0;
}
