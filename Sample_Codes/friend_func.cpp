#include <bits/stdc++.h>
using namespace std;

class sample
{
    int a, b, c;
    public:
    void setdata();
    friend int max(sample obj);
};
void sample::setdata()
{
    cin >> a >> b >> c;
}
int max(sample obj)
{
    if (obj.a > obj.b && obj.a >> obj.c)
    {
        return obj.a;
    }

    else if (obj.b > obj.a && obj.b >> obj.c)
    {
        return obj.b;
    }

    else
    {
        return obj.c;
    }
}

int main()
{

    sample obj;
    obj.setdata();
    cout << max(obj);

    return 0;
}