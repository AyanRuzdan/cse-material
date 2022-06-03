#include<iostream>
using namespace std;
class length
{
	protected:
		int l;
};
class breadth:public length
{
	protected:
		int b;
};
class height:public breadth
{
	protected:
		int h;
};
class volume:public height
{
	public:
		void get_data()
		{
			cout<<"\n Enter length, breadth and height:";
			cin>>l>>b>>h;
		}
		void result()
		{
			cout<<"Volume is:"<<l*b*h;
		}
};
int main()
{
	volume obj1;
	obj1.get_data();
	obj1.result();
	return 0;
}
