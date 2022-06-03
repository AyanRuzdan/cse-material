#include<iostream>
using namespace std;
int main()
{
string s1("Hello");
cout<<s1<<endl;
string s2(s1);
cout<<s2<<endl;
string s3;
cout<<s2[0];
if(s1==s2)
{
cout<<"\n Equal";
}
cout<<"\n Enter string:";
getline(cin,s3);
cout<<s3;
}
