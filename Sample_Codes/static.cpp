#include <iostream>
using namespace std;

class RegNo
{
public:
    static int reg;
    int num;

    void setdata();
    void showdata();
};

int RegNo ::reg = 2000;

void RegNo ::setdata()
{
    num = ++reg;
}

void RegNo ::showdata()
{
    cout << num << endl;
}

int main()
{
    int n;
    cout << "No of users : ";
    cin >> n;
    RegNo arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].setdata();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].showdata();
    }

    cout << "Total num of uers" << RegNo ::reg - 2000 << endl;

    return 0;
}