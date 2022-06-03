//Random access-Reading any particular object(or record) from the file
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
fflush(stdin);
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
Employee e;
int no;
FILE.open("employee1",ios::in|ios::binary);
cout<<"\n Enter the object whose record has to be displayed:";
cin>>no;
int location=(no-1)*sizeof(e);
FILE.seekg(location);
FILE.read((char*)&e,sizeof(e));
e.show_data();
}
