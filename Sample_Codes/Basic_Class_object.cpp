#include<iostream>
using namespace std;
class abc
{
    int x,y;
public:
    void getdata()
    {
        cout<<"Enter the values of x and y:"<<endl;
        cin>>x>>y;
    }
    void sum()
    {
        int z;
        z=x+y;
        cout<<"The sum is:"<<z;
    }

};
int main()
{
  abc obj1;
  obj1.getdata();
  obj1.sum();
}
