//Syntax for declaring a pointer to normal variable:data_type *ptr_var
//Syntax for declaring a pointer to a class data member:data_type class_name::*ptr_var;
//Syntax for assigning an address to a normal pointer variable is:ptr_var=&variable
//Syntax for assigning the address of a class data member:ptr_var=&class_name::data_member_name
//We can declare and assign pointer variables in the same line by writing:data_type *ptr_var=&variable
//Here:-data_type class_name::*ptr_var=&class_name::data_member_name
#include<iostream>
using namespace std;
class Test
{
public:
int x;
void show_data();
};
void Test::show_data()
{
cout<<"\n x="<<x;
}
int main()
{
Test t;
int Test::*ptr=&Test::x;
//int Test::*ptr;
//ptr=&Test::x;
t.*ptr=20;//.* is member dereferencing operator
t.show_data();
/*Test *tp=new Test;//Dynamically allocate memory for object
tp->*ptr=80;
tp->show_data();
(*tp).*ptr=70;
(*tp).show_data();*/
}
