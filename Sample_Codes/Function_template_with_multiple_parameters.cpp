//Function template with more than one generic types
#include<iostream>
using namespace std;
template<class T1,class T2>
void multiply(T1 num1,T2 num2)
{
cout<<num1*num2;
}
int main()
{
int num1=3;
float num2=4.5;
cout<<"\n Product of num1*num2=";
multiply<int,float>(num1,num2);
cout<<endl;
multiply<int,int>(2,2);
float num3=7.8;
int num4=3;
cout<<"\n Product of num3*num4=";
multiply<float,int>(num3,num4);
cout<<endl;
multiply<float,float>(2.3,4.5);
return 0;
}




