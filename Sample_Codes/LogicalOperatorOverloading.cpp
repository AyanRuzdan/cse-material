#include <iostream>
using namespace std;
class logical
{
    int x;

public:
    logical()
    {
        x = 0;
    }
    logical(int a)
    {
        x = a;
    }
    bool operator&&(logical o)
    {
        return (x && o.x);
    }
    friend int operator||(logical, logical);
};
int operator||(logical o1, logical o2)
{
    return (o1.x + o2.x);
}
int main()
{
    logical o1(6), o2(5);
    int x = o1 && o2;
    // int x=o1.operator&&(o2);
    cout << x << endl;
    int y = o1 || o2;
    // int y=operator||(o1,o2);
    cout << endl
         << y;
    return 0;
}