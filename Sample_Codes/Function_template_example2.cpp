#include<iostream>
using namespace std;
template<class T>
T min1(T a,T b)
{
return(a<b?a:b);
}
int main()
{
int x,y;
float p,q;
cout<<"\nEnter integer values";
cin>>x>>y;
cout<<"\nEnter float values";
cin>>p>>q;
cout<<"\nMin of integer values"<<min1<int>(x,y);
cout<<"\nMin of floating value"<<min1<float>(p,q);
return 0;
}
