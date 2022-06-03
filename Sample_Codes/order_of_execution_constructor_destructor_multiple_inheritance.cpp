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
};
class N
{
	protected:
		int n;
		public:
		N(int y)
		{
		    n=y;
		    cout<<"\nIn N";

		}
};
class P:public M,public virtual N//ORDER OF INHERITANCE
{
	int l;
	public:
		P(int p,int q,int r):N(q),M(r)
		{
		l=p;
		cout<<"\nIn P";
		}
		void display()
		{
		cout<<"m="<<m<<" "<<"n="<<n<<" "<<"l="<<l;
		}
};
int main()
{
	P obj1(3,2,1);
	obj1.display();
	return 0;
}
