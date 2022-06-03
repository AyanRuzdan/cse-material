#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int marks[]={98,67,89,100,45,65,51,78,12,43};
int arr[10]={0};
fstream FILE;
FILE.open("temp",ios::out|ios::binary);
FILE.write((char *)marks,sizeof(marks));
FILE.close();
FILE.open("temp",ios::in|ios::binary);
FILE.read((char *)arr,sizeof(arr));
cout<<"\n Marks obtained:";
for(int i=0;i<10;i++)
cout<<"\t"<<arr[i];
FILE.close();
}




