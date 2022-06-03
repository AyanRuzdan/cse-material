#include<iostream>
using namespace std;
class A
{
	protected:
		int x;
	public:
		void display1()
		{
			cout<<"\n Value of x is:"<<x;
		}
};
class B:public A
{
	private:
		int y;
		public:
			void getdata()
			{
				cout<<"\n Enter the values of x and y:";
				cin>>x>>y;
			}
			void display2()
			{
				cout<<"\n Value of y is:"<<y;
			}
			void add()
			{
				cout<<"\n Sum of data members is:"<<x+y;
			}
};
int main()
{
	B obj1;
	obj1.getdata();
	obj1.display1();
	obj1.display2();
	obj1.add();
}
