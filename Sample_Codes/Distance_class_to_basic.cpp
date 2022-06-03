//Class to basic conversion is done with the help of operator function
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
void get_data()
{
cin>>km>>m;
}
operator int()
{
int d=km*1000+m;
return d;
}
};
int main()
{
int distance;
Distance1 T1;
cout<<"\n Enter the number of kilometers and metres";
T1.get_data();
distance=T1;//(int)T1
cout<<"\n Total Distance="<<distance;
}
