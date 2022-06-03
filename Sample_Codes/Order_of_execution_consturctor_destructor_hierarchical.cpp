#include<iostream>
using namespace std;
class M
{
	protected:
		int m;
		public:
		M(int x)
		{
		    m=x;
		    cout<<"\nIn M";
		}
		~M()
		{
			cout<<"\n Base class desturctor";
		}
};
class N:public M
{
	protected:
		int n;
		public:
		N(int y):M(y)
		{
		    n=y;
		    cout<<"\nIn N:"<<n;

		}
		~N()
		{
			cout<<"\n Derived class N desturctor";
		}
		
};
class P:public M
{
	int l;
	public:
		P(int p):M(p)
		{
		l=p;
		cout<<"\nIn P:"<<l;
		}
		~P()
		{
			cout<<"\n Derived class P desturctor";
		}
};
int main()
{
	N obj1(1);
	P obj2(2);
	return 0;
}
