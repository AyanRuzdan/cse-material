#include<iostream>
using namespace std;
class abc
{
	int a,b;
	public:
		void getdata();	
		void showdata();
};
void abc::getdata()
{
	cout<<"\n Enter values of a and b:";
	cin>>a>>b;
}
void abc::showdata()
{
	cout<<"\n Values of a and b are:"<<a<<" "<<b;
}
int main()
{
	abc obj1;
	obj1.getdata();
	obj1.showdata();
	return 0;
}
