#include<iostream>
using namespace std;
int area(int);
int area(int,int);
float area(float);
int main()
{
cout<<"Calling the area function for square"<<area(5)<<"\n";
cout<<"Calling the area function for rectangle"<<area(5,10)<<"\n";
cout<<"Calling the area function for circle"<<area(5.5f)<<"\n";
}
int area(int side)
{
return(side*side);
}
int area(int length,int breadth)
{
return(length*breadth);
}
float area(float radius)
{
return(3.14*radius*radius);
}
