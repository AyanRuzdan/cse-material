#include<iostream>
using namespace std;
class abc_parameter
{
    int x,y;
    public:
    abc_parameter(int a,int b)
    {
        x=a;
        y=b;
    }
    void display()
    {
        cout<<"\n Values of x and y are:"<<x<<" "<<y;
    }
};
int main()
{
	abc_parameter obj1(2,3),obj2(4,5);//First Way of calling constructor
    abc_parameter obj3=abc_parameter(6,7);//Second Way of calling constructor
    obj1.display();
    obj2.display();
    obj3.display();
    return 0;
}
