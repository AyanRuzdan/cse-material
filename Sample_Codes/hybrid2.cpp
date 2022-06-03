#include<iostream>
using namespace std;
class A
{
	protected:
		float p;
	public:
		void getdataA()
		{
			cout<<"\n Enter value of p:";
			cin>>p;
		}
};
class B:public A
{
	protected:
		float q;
	public:
		void getdataB()
		{
			cout<<"\n Enter value of q:";
			cin>>q;
		}
};
class C
{
	protected:
		float r;
		public:
		void getdataC()
		{
			cout<<"\n Enter value of r:";
			cin>>r;
		}	
};
class D:public B,public C
{
	public:
		void average()
		{
			cout<<"\n Average is:"<<(p+q+r)/3.0;
		}
};
int main()
{
	D obj1;
	obj1.getdataA();
	obj1.getdataB();
	obj1.getdataC();
	obj1.average();
	return 0;
}
