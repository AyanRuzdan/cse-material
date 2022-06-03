#include<iostream>
using namespace std;
template<class T>
void display(T x) //Function template with one generic type
{
	cout<<"Template display:"<<x<<"\n";
}
template<class T1,class T2,class T3>
void display(T1 x,T2 y,T3 z) //Function template with three generic types
{
	cout<<"Template display:"<<x<<" "<<y<<" "<<z<<"\n";
}
void display(int x)//Non-template function accepting one integer argument
{
	cout<<"Explicit display:"<<x<<"\n";
}
void display(char y)//Non-template function accepting one character argument
{
	cout<<"Explicit display:"<<y<<"\n";
}
int main()
{
display(100); //Calls display(non-template) which accepts one integer argument
display(56.78);//Calls display(template) accepting one generic type
display('a');// Calls display(non-template) which accepts one character argument
display(5.98,'b',89);// Calls display(template) accepting three generic types
return 0;
}
