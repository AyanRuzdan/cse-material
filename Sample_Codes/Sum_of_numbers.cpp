#include <iostream>
using namespace std;
int addNumbers(int n);
int main()
{
    int num;
    cout<<"Enter a positive integer:";
    cin>>num;
    cout<<"Addition of numbers is:"<<addNumbers(num);
    return 0;
}

int addNumbers(int n)
{
    if(n != 0)
        return n + addNumbers(n-1);
    else
        return n;
}
