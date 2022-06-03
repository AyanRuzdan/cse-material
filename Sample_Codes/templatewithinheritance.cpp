#include<iostream>
using namespace std;
template<class T>
class alpha
{
protected:
T a;
public:
    void check()
    {
        cout<<"\nHello";
    }
};
template <class T,class T1>
class beta:public alpha <T>
{
private:
T1 b;
public:
void get()
{
cin>>alpha<T>::a>>b;
}
void display()
{
cout<<"a: "<<alpha<T>::a<<endl;
cout<<"b: "<<b<<endl;
alpha<T>::check();
}
};
int main()
{
beta<int,float> b1;
beta<float,int> b2;
cout<<"\nEnter a(int) and b(float)";
b1.get();
b1.display();
cout<<"\nEnter a(float) and b(int)";
b2.get();
b2.display();
return 0;
}

