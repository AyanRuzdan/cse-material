#include<iostream>
using namespace std;
template<class T>
void swap1(T a,T b)
{
T temp=a;
a=b;
b=temp;
}
int main()
{
int inum1=4,inum2=5;
float fnum1=4.8,fnum2=5.3;
char c1='A',c2='a';
cout<<"\n Before swapping:";
cout<<"\n inum1="<<inum1<<" and inum2="<<inum2;
cout<<"\n fnum1="<<fnum1<<" and fnum2="<<fnum2;
cout<<"\n c1= "<<c1<<" and c2="<<c2;
swap1<int>(inum1,inum2);
swap1<float>(fnum1,fnum2);
swap1<char>(c1,c2);
cout<<"\n\n After Swapping:";
cout<<"\n inum1="<<inum1<<" and inum2="<<inum2;
cout<<"\n fnum1="<<fnum1<<" and fnum2="<<fnum2;
cout<<"\n c1= "<<c1<<" and c2="<<c2;
return 0;
}
