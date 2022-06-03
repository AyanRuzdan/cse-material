//Class to basic conversion is done with the help of operator function
#include<iostream>
using namespace std;
class area
{
private:
double radius;
public:
area()
{
radius=0.0;
}
void get_data()
{
cin>>radius;
}
operator double()
{
double ans=3.14*radius*radius;
return ans;
}
};
int main()
{
double final1;
area T1;
cout<<"\n Enter the radius";
T1.get_data();
final1=T1;
cout<<"\n Area="<<final1;
}
