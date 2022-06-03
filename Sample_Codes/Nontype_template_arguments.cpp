#include <iostream>
using namespace std;
template<class T, int size>
class A
{
    public:
    T arr[size];
    void insert1()
    {
        int i =1;
        for (int j=0;j<size;j++)
        {
            arr[j] = i;
            i++;
        }
    }
    void insert2()
    {
        float i=1.1f;
        for (int j=0;j<size;j++)
        {
            arr[j] = i;
            i=i+1.1f;
        }
    }
    void insert3()
    {
        double i=11.12;
        for (int j=0;j<size;j++)
        {
            arr[j] = i;
            i=i+11.12;
        }
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    A<int,10> t1;
    t1.insert1();
    t1.display();
    A<float,10>t2;
    t2.insert2();
    cout<<endl;
    t2.display();
    A<double,10>t3;
    t3.insert3();
    cout<<endl;
    t3.display();
    return 0;
}
