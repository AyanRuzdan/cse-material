#include<iostream>
#include<conio.h>
using namespace std;
class employee
{
	char name[50];
	int age;
	public:
		void getdata(void);
		void putdata(void);
};
void employee::getdata(void)
{
	cout<<"\n Enter the name of employee:";
	cin>>name;
	cout<<"\n Enter the age of employee:";
	cin>>age;
}
void employee::putdata(void)
{
	cout<<"\n Entered name is:"<<name;
	cout<<"\n Entered age is:"<<age;
}
const int size=3;
int main()
{
	employee emp[size];
	int i;
	for(i=0;i<3;i++)
	{
		cout<<"\n Enter details of employee number"<<i+1;
		emp[i].getdata();
	}
	for(i=0;i<3;i++)
	{
		cout<<"\nDetails of the employee number"<<i+1;
		emp[i].putdata();
	}
	getch();
	return 0;
}
