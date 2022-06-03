#include<iostream>
using namespace std;
class K17KK;
class K17SD
{
    int x,y,z;
public:
    void getdata()
    {
        cout<<"Enter values:"<<endl;
        cin>>x>>y>>z;
    }
    friend class K17KK;

};
class K17KK
{
public:
    void task1(K17SD s)
    {
        int sum=s.x+s.y+s.z;
        cout<<"The sum is:"<<sum;
    }
    void task2(K17SD s)
    {

        if(s.x<s.y &&s.x<s.z)
        {

            cout<<"Smallest is:"<<s.x;
        }
        else if(s.y<s.x &&s.y<s.z)
        {

            cout<<"Smallest is:"<<s.y;
        }
        else
        {
        cout<<"Smallest is:"<<s.z;
        }
    }
    void task3(K17SD s)
    {

        cout<<"Multiplication is:"<<s.x*s.y*s.z;
    }
};
int main()
{
    K17SD obj1;
    obj1.getdata();
    K17KK obj2;
    obj2.task1(obj1);
    obj2.task2(obj1);
    obj2.task3(obj1);

}
