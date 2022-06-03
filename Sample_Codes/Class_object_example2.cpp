#include<iostream>
using namespace std;
class item
{
int number;
float cost;
public:
	void getdata(int a,float b)
	{
	number=a;
	cost=b;
	}
	//Defining member function inside class definition
    void putdata(void)
	{
		cout<<"Number:"<<number<<"\n";
		cout<<"Cost:"<<cost<<"\n";
	}
};
int main()
{
	item x;
	cout<<"\nObject x="<<"\n";
	x.getdata(100,299.95);
	x.putdata();

	item y;
	cout<<"\nobject y="<<"\n";
	y.getdata(200,175.50);
	y.putdata();
	return 0;
}
