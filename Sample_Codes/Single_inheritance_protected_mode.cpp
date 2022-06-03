#include<iostream>
#include<string.h>
using namespace std;
class student
{
private:
int roll_no;
protected:
char section[10];
public:
void get_rno()
{
cout<<"\n Enter the roll number:";
cin>>roll_no;
}
void show_rno()
{
cout<<"\n Roll no:"<<roll_no;
}
};
class result:protected student
{
private:
float fees;
public:
void get_data()
{
get_rno();
cout<<"\n Enter fees:";
cin>>fees;
cout<<"\n Enter section:";
cin>>section;
}
void display()
{
show_rno();
cout<<"\n Fees:"<<fees;
cout<<"\n Section:"<<section;
}
} ;
int main()
{
result obj1;
obj1.get_data();
obj1.display();
//obj1.get_rno(); //It  not will work
//obj1.roll_no=78;//It will not work(Private data)
//strcpy(obj1.section,"K17MM");//It will not work(Protected data)
}
