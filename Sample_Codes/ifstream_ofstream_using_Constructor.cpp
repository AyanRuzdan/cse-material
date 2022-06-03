#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
char name[10];
float sal;
ofstream outFile("K21PG.txt");//Opening file for writing
if(!outFile)
{
cout<<"\n File could not be opened";
exit(1);//Abnormal termination
}
for(int i=0;i<3;i++)
{
cout<<"\n Enter the name and salary of Employee"<<i+1<<" : ";
cin>>name>>sal;
outFile<<"\n"<<name<<"\t"<<sal;
}
outFile.close();
ifstream inpFile("K21PG.txt");//Opening file for reading
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
