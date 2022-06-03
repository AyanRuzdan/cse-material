#include<iostream>
using namespace std;
class abc_overloading
{
    int x,y;
    public:
    abc_overloading()
    {
        x=2;
        y=3;
    }
    abc_overloading(int a,int b)
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
    abc_overloading obj1;
    obj1.display();
    abc_overloading obj2(4,5);
    obj2.display();
    return 0;
}
