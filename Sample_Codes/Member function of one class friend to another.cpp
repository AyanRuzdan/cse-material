//Member function of one class acting act as friend function to another class
#include <iostream>
using namespace std;
class B;
class A 
{
public:
	void access(B);
};
class B 
{
int b;
public:
void input()
{
    cout<<"\nEnter b:";
    cin>>b;
}
friend void A::access(B obj); // Friend function
};
void A::access(B obj)
{
	cout << "Accessing data member b = " << obj.b;
}

int main()
{
	A A1;
	B B1;
	B1.input();
	A1.access(B1);
	return 0;
}
