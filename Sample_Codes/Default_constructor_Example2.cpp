#include<iostream>
using namespace std;
class abc_default
{
    int x,y;
    public:
    abc_default()
    {
        cout<<"\n Enter the values for x and y:";
        cin>>x>>y;
    }
    void display()
    {
        cout<<"\n Values of x and y are:"<<x<<" "<<y;
    }

};
int main()
{
    abc_default obj[2];
    obj[0].display();
    obj[1].display();
    return 0;
}
