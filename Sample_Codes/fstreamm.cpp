//open() member function
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
char name[10];
float sal;
fstream obj;
obj.open("newfile3.txt",ios::out);
if(!obj)
{
cout<<"\n File could not be opened";
exit(1);
}
for(int i=0;i<3;i++)
{
cout<<"\n Enter the name and salary of Employee"<<i+1<<" : ";
cin>>name>>sal;
obj<<"\n"<<name<<"\t"<<sal;
}
obj.close();
obj.open("newfile3.txt",ios::in);
if(!obj)
{
cout<<"\n File could not be opened";
exit(1);
}
for(int i=0;i<3;i++)
{
obj>>name;
obj>>sal;
cout<<"\n Employee"<<i+1<<" : ";
cout<<name<<"\t"<<sal;
}
obj.close();
}
