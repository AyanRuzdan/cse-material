//Basic to class is done with the help of constructor function
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
Time(int t)
{
h=t/60;
m=t%60;
}
void show_data()
{
cout<<h<<"hrs"<<m<<"mins";
}
};
int main()
{
int min;
cout<<"\n Enter the minutes:";
cin>>min;
Time T1;
T1=min;//It will call the constructor function after taking minutes
T1.show_data();
}

