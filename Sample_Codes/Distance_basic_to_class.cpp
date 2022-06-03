//Basic to class is done with the help of constructor function
#include<iostream>
using namespace std;
class Distance1
{
private:
int km,m;
public:
Distance1()
{
km=m=0;
}
Distance1(int d)
{
km=d/1000;
m=d%1000;
}
void show_data()
{
cout<<km<<"Kilometers"<<m<<"meters";
}
};
int main()
{
int d;
cout<<"\n Enter the distance:";
cin>>d;
Distance1 d1;
d1=d;//It will call the constructor function after taking minutes
d1.show_data();
}

