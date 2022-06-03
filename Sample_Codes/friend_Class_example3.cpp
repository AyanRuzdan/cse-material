#include<iostream>
using namespace std;
class ABC;
class XYZ
{
	int x,y;
	public:
		void getdata()
		{
			cout<<"\n Enter x and y:";
			cin>>x>>y;
		}
		friend class ABC;
};
class ABC
{
	public:
		void square(XYZ obj)
		{
			cout<<"\nSquare is:"<<obj.x*obj.x;
		}
		void cube(XYZ obj)
		{
			cout<<"\nCube is:"<<obj.y*obj.y*obj.y;
		}
};
int main()
{
	XYZ X;
	ABC A;
	X.getdata();
	A.square(X);
	A.cube(X);
	return 0;
}
