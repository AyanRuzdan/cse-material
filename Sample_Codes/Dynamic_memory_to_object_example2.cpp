#include<iostream>
#include<stdlib.h>
using namespace std;
class Employee
{
int id;
float salary;
public:
void input()
{
cout<<"\n Enter id:";
cin>>id;
cout<<"\n Enter salary:";
cin>>salary;
}
void display()
{
cout<<"\n"<<id<<" "<<salary;
}
};
int main()
{
int n;
cout<<"\n Enter number of employees:";
cin>>n;
Employee *p=new Employee[n];
Employee *d=p;
Employee *flag=p;
if(p==NULL)
{
cout<<"\n Memory allocation failure";
exit(1);
}
for(int i=0;i<n;i++)
{
p->input();
p++;
}
for(int i=0;i<n;i++)
{
d->display();
d++;
}
delete[]flag;
return 0;
}
