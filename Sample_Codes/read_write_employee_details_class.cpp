#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
private:
int emp_code;
char name[20];
int hra;
int da;
int ta;
public:
void read_data()
{
cout<<"\n\n Enter the employee code:";
cin>>emp_code;
cout<<"\n\n Enter the name of the employee:";
cin>>name;
cout<<"\n\n Enter the HRA,DA and TA:";
cin>>hra>>da>>ta;
}
void show_data()
{
cout<<"\n\n EMP CODE: "<<emp_code;
cout<<"\n\n NAME: "<<name;
cout<<"\n\n HRA,DA and TA: "<<hra<<"\t"<<da<<"\t"<<ta;
}
};
int main()
{
fstream FILE;
Employee e[3],d[3];
int i;
FILE.open("employee1",ios::out|ios::binary);
cout<<"\n Enter the details of three employees";
cout<<"\n---------------------------------------";
for(i=0;i<3;i++)
{
e[i].read_data();
FILE.write((char *)&e[i],sizeof(e[i]));
}
FILE.close();
FILE.open("employee1",ios::in|ios::binary);
for(i=0;i<3;i++)
{
FILE.read((char*)&d[i],sizeof(d[i]));
d[i].show_data();
}
FILE.close();
return 0;
}
