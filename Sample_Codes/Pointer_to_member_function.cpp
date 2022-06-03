#include<iostream>
using namespace std;
class Test
{
public:
void show_msg(int);
};
void Test::show_msg(int x)
{
cout<<"\n Hello World!!!"<<x;
}
int main()
{
void(Test::*fp)(int)=&Test::show_msg;
//Return type of function is void and it is not accepting any argument
Test t;
(t.*fp)(5);//.*(Member dereferencing operator
/*Test *ptr=new Test;
(ptr->*fp)(5);*/
}
