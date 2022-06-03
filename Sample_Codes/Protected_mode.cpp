#include<iostream>
using namespace std;
class A
{
	protected:
		int x,y;
		public:
			void showdataA()
			{
				cout<<x<<" "<<y<<" ";
			}
};
class B:protected A
{
	protected:
		int z;
		public:
			void getdata()
			{
cout<<"\n Enter values of x ,y and z:";
cin>>x>>y>>z;// x and y are protected in B also, but they are accessible inside class
			}
			void showdataB()
			{
				showdataA();
				cout<<z;
			}
};
int main()
{
	B obj1;
	obj1.getdata();
	obj1.showdataB();
//obj1.showdataA(); //We cannot access, as showdataA() is protected in B
//cout<<obj1.x<<" "<<obj1.y;  //We cannot access, as x and y are protected in B
}
