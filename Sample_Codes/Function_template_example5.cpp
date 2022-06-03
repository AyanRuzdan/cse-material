#include<iostream>
using namespace std;
template<class T>
T rectangle(T num1,T num2)
{
return (num1*num2);
}
int main()
{
int num1=3,num2=4;
cout<<"\n Area of rectangle="<<rectangle<int>(num1,num2);
float num3=5.6,num4=9.8;
cout<<"\nArea of rectangle="<<rectangle<float>(num3,num4);
double num5=123.456,num6=3.44444;
cout<<"\nArea of rectangle="<<rectangle<double>(num5,num6);
return 0;
}




