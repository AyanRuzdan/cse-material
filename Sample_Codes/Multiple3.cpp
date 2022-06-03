#include<iostream>
using namespace std;
class B1
{
	protected:
		int x;
	public:
		void getdataB1()
		{
			cout<<"\n Enter value of x:";
			cin>>x;
		}
};
class B2
{
    protected:
		int y;
	public:
		void getdataB2()
		{
			cout<<"\n Enter value of y:";
			cin>>y;
		}	
};
class D:public B1,public B2
{
	public:
		void check()
		{
			if(x==y)
			{
				cout<<"\n x and y are equal";
			}
			else if(x>y)
			{
				cout<<"\n x is greater than y";
			}
			else
			{
				cout<<"\n y is greater than x";
			}
		}
};
int main()
{
	D obj1;
	obj1.getdataB1();
	obj1.getdataB2();
	obj1.check();
	return 0;
}
