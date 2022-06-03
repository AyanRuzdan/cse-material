#include<iostream>
using namespace std;
inline double div(double p,double q)
{
	return(p/q);
}
int main()
{
	double a=12.4;
	double b=4.0;
	cout<<div(a,b)<<"\n";
	return 0;
}
