#include<iostream>
using namespace std;
class A
{
	protected:
		int x;
	public:
		void getdataA()
		{
			cout<<"\n Enter value of x:";
			cin>>x;
		}
};
class B:public A
{
	protected:
		int y,z;
		public:
			void getdataB()
			{
				cout<<"\n Enter value of y:";
				cin>>y;
			}
			void sum()
			{
				z=x+y;
			}
};
class C:public B
{
	public:
		void check()
		{
			if(z%2==0)
			{
				cout<<"\n z is even";
			}
			else
			{
				cout<<"\n z is odd";
			}
		}
	
	
};
int main()
{
	C obj1;
	obj1.getdataA();
	obj1.getdataB();
	obj1.sum();
	obj1.check();
	return 0;
}
