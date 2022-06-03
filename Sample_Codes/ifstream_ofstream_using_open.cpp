//open() member function
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
char name[10];
float sal;
ofstream outFile;
outFile.open("newfile1.txt");
if(!outFile)
{
cout<<"\n File could not be opened";
exit(1);
}
for(int i=0;i<3;i++)
{
cout<<"\n Enter the name and salary of Employee"<<i+1<<" : ";
cin>>name>>sal;
outFile<<"\n"<<name<<"\t"<<sal;
}
outFile.close();
ifstream inpFile;
inpFile.open("newfile1.txt");
if(!inpFile)
{
cout<<"\n File could not be opened";
exit(1);
}
for(int i=0;i<3;i++)
{
inpFile>>name;
inpFile>>sal;
cout<<"\n Employee"<<i+1<<" : ";
cout<<name<<"\t"<<sal;
}
inpFile.close();
}
