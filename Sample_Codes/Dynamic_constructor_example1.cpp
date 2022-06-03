#include <iostream>
using namespace std;

class example1 {
	const char* ptr;
public:
	// default constructor
	example1()
	{
		// allocating memory at run time
		ptr = new char[8];
		ptr = "Dynamic";
	}
	void show()
	{
		cout << ptr << endl;
	}
};

int main()
{
	example1 *ptr = new example1();
	ptr->show();
}
