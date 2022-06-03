#include<iostream>
using namespace std;
class example
{
	int l,b;
	public:
		void getdata()
		{
			cout<<"\n Enter the values of length and breadth:";
			cin>>l>>b;
		}
		friend void area1(example);
		friend void area2(example);
};
void area1(example x)
{
	cout<<"\n Area of square is:"<<x.l*x.l;
}
void area2(example x1)
{
	cout<<"\n  Area of rectangle is:"<<x1.l*x1.b;
}
int main()
{
	example obj1;
	obj1.getdata();
	area1(obj1);
	area2(obj1);
	return 0;
}
