#include<iostream>
using namespace std;
class academics
{
protected:
int studies;
public:
void get_data()
{
cout<<"\nEnter marks in studies:";
cin>>studies;
}
};
class sports
{
protected:
int sports_wt;
public:
void input()
{
cout<<"\nEnter marks in sports:";
cin>>sports_wt;
}
};
class result:public academics,public sports
{
public:
void calculate()
{
cout<<"\nAverage marks are:"<<(studies+sports_wt)/2.0f;
}
};
int main()
{
result obj1;
obj1.get_data();
obj1.input();
obj1.calculate();
}
