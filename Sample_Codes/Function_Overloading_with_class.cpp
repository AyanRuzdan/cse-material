#include<iostream>
using namespace std;
class overloading
{
public:
int area(int side)
{
	return (side*side);
}
int area(int length,int breadth)
{
	return (length*breadth);
}
float area(float radius)
{
	return (3.14*radius*radius);
}
};
int main()
{
	overloading obj1;
	int square,rectangle;
	float circle;
	square=obj1.area(5);
	cout<<"\n Area of square is:"<<square;
	rectangle=obj1.area(3,4);
	cout<<"\n Area of rectangle is:"<<rectangle;
	circle=obj1.area(3.4f);
	cout<<"\n Area of circle is:"<<circle;
	return 0;
}
