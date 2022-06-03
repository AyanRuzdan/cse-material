#include<iostream>
using namespace std;
class Sample
{
private:
static int num_objects;
static int num_objects_destroyed;
public:
Sample()
{
num_objects++;
}
~Sample()
{
num_objects_destroyed++;
}
void show_data()
{
cout<<"\n\n Number of objects created:"<<num_objects;
cout<<"\n Number of objects destroyed:"<<num_objects_destroyed;
cout<<"\n Number of objects active:"<<num_objects-num_objects_destroyed;
}
};
int Sample::num_objects=0;
int Sample::num_objects_destroyed=0;
void my_func()
{
Sample s8,s9;
s9.show_data();
}
int main()
{
Sample s1,s2,s3;
{
s1.show_data();//Created:3,Destroyed:0,Active:3
Sample s4;
{
Sample s5;
s5.show_data();//Created:5,Destroyed:0,Active:5
}
}
s3.show_data();//Created:5,Destroyed:2,Active:3//Leaving local scope
my_func();//Created:7,Destroyed:2,Active:5
s2.show_data();//Created:7,Destroyed:4,Active:3//Leaving function scope
return 0;
}