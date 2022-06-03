//Memory allocation and deallocation for single memory
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int *p=NULL;
p=new int(12);
/*if(!p)
{
    cout<<"\n Memory allocation failure";
    exit(1);
}*/
if(p==NULL)
{
    cout<<"\n Memory allocation failure";
    exit(1);
}
else
{
cout<<"Memory allocated successfully\n";
//*p=12;
cout<<"Integer value stored is:"<<*p;
delete p;//Deallocation of memory
cout<<"\n Memory deallocated";
}
return 0;
}
