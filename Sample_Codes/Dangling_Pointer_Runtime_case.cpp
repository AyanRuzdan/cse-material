#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int *p=NULL;
p=new int;
if(p==NULL)
{
    cout<<"\n Memory allocation failure";
    exit(1);
}
/*if(!p)
{
    cout<<"\n Memory allocation failure";
    exit(1);
}*/
*p=12;
cout<<"\nAddress is(before deallocation):"<<p;
delete p;//Deallocation of memory
cout<<"\nAddress is(after deallocation):"<<p;//p is a dangling pointer
p=NULL;//Avoiding dangling pointer situation-Solution
cout<<"\n New address in p is:"<<p;
return 0;
}
