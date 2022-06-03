//Class to basic conversion is done with the help of operator function
#include<iostream>
using namespace std;
class Time
{
private:
int h,m;
public:
Time()
{
h=m=0;
}
void get_data()
{
cin>>h>>m;
}
operator int()
{
int t=h*60+m;
return t;
}
};
int main()
{
int min;
Time T1;
cout<<"\n Enter the number of hrs and mins";
T1.get_data();
min=T1;//(int)T1(internal representation)
cout<<"\n Total Minutes="<<min;
}
