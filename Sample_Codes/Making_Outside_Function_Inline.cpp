#include<iostream>
using namespace std;
class item
{
int number;
float cost;
public:
	void getdata(int a,float b);
	//Defining member function inside class definition
	void putdata()
	{
		cout<<"Number:"<<number<<"\n";
		cout<<"Cost:"<<cost<<"\n";
	}
};
//Defining member function outside the class definition
inline void item::getdata(int a,float b)
{
	number=a;
	cost=b;
}
int main()
{
	item x;
	cout<<"\nObject x="<<"\n";
	x.getdata(100,299.95);
	x.putdata();
	return 0;
}
