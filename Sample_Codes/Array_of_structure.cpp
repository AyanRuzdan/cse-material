#include<iostream>
using namespace std;
struct employee
{
	int id;
	char name[50];
	float salary;
};
int main()
{
	employee obj[2];
	int i;
	for(i=0;i<2;i++)
	{
		cout<<"Enter the details:"<<endl;
		cout<<"\nEnter the name:";
		cin.getline(obj[i].name,50);
		cout<<"\n Enter the id:";
		cin>>obj[i].id;
		cout<<"Enter the salary"<<endl;
		cin>>obj[i].salary;
		//cin.ignore();
	}
	for(i=0;i<2;i++)
	{
		cout<<"\n Details are:";
		cout<<obj[i].id<<endl;
		cout<<obj[i].name<<endl;
		cout<<obj[i].salary<<endl;
	}
}
