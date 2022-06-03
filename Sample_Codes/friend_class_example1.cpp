#include<iostream>
using namespace std;
class ABC;
class XYZ
{
	int data_XYZ;
	public:
		void set(int value)
		{
			data_XYZ=value;
		}
		friend class ABC;

};
class ABC
{
	int data_ABC;
	public:
		void setvalue(XYZ obj1)
		{
			data_ABC=obj1.data_XYZ;
			cout<<"Value is:"<<data_ABC;
		}
};
int main()
{
	XYZ X;
	ABC A;
	X.set(5);
	A.setvalue(X);
	return 0;
}





