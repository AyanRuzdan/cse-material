#include<iostream>
using namespace std;
class B
{
	protected:
		int x;
	public:
		void getdata()
		{
			cout<<"\n Enter value of x:";
			cin>>x;
		}
};
class D1:public B
{
	public:
		void taskD1()
		{
			cout<<"\n Square of x is:"<<x*x;
		}
};
class D2:public B
{
	public:
		void taskD2()
		{
			cout<<"\n Cube of x is:"<<x*x*x;
		}
};
int main()
{
	D1 obj1;
	obj1.getdata();
	obj1.taskD1();
	D2 obj2;
	obj2.getdata();
	obj2.taskD2();
	return 0;
}
