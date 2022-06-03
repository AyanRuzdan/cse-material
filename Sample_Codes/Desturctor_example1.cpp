/*Name of destructor is same as that of the class
Destructor's name is preceded by tilde symbol ~
A destructor is also called when the programmer explicitly deletes an object using
the delete operator
Like a constructor,a destructor is also declared in the public section
The order of invoking a destructor is the reverse of invoking a constructor
Destructor do not take any argument and hence cannot be overloaded
A destructor does not return any value
Destructor is automatically invoked when the object goes out of scope
Such as-the function ends,the program ends,a block containing local variable ends
When delete operator is called*/
#include<iostream>
using namespace std;
class Sample
{
private:
int x;
public:
Sample(int n)
{
x=n;
cout<<"\n Constructor Called for object with value:"<<x;
}
~Sample()
{
cout<<"\n Destructor Called for object with value:"<<x;
}
};
int main()
{
Sample s1(1);
Sample s2(2);
Sample s3(3);
return 0;
}
