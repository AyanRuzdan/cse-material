#include<iostream>
#include<conio.h>
using namespace std;
class ABC;//Forward declaration--It is done when class is used before its definition
class XYZ
{
	int data;
	public:
		void setvalue(int value)
		{
			data=value;
		}
		friend void add(XYZ,ABC);
};
class ABC
{
	int data;
	public:
		void setvalue(int value)
		{
			data=value;
		}
        friend void add(XYZ,ABC);
};
void add(XYZ obj1,ABC obj2)
{
	cout<<"Sum is="<<obj1.data+obj2.data;
}
int main()
{
	XYZ X;
	ABC A;
	X.setvalue(5);
	A.setvalue(50);
	add(X,A);
	return 0;
}





