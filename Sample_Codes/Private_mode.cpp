//Private mode of inheritance(Single level inheritance)
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
class B:private A
{
	private:
		int z;
		public:
			void getdata()
			{
cout<<"\n Enter values of x ,y and z:";
cin>>x>>y>>z;// x and y are private in B, but they are accessible inside class
			}
			void showdataB()
			{
				showdataA();//called like a nested member function
				cout<<z;
			}
};
int main()
{
	B obj1;
	obj1.getdata();
	obj1.showdataB();
//obj1.showdataA(); //We cannot access, as showdataA() is private in B
cout<<obj1.x<<" "<<obj1.y;  //We cannot acces, as x and y are private in B
}
