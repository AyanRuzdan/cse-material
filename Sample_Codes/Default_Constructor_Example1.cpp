#include<iostream>
using namespace std;
class abc_default
{
    int x,y;
    public:
    abc_default()
    {
        x=2;
        y=3;
        cout<<"\n Data members are initialized";
    }
    void display()
    {

        cout<<"\n Values of x and y are:"<<x<<" "<<y;
    }

};
int main()
{
    abc_default obj1;
    obj1.display();
    return 0;
}
