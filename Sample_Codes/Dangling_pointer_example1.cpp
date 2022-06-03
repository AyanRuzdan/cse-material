#include<iostream>
using namespace std;
int main()
{
   int *ptr;
   {
       int v=23;
       ptr = &v;
       cout<<"Value is(inside block):"<<*ptr<<"\n";
       cout<<"Address is(inside block):"<<ptr<<"\n";
   }
   // Here ptr is dangling pointer as v is no longer existing
cout<<"Value is(outside block):"<<*ptr<<"\n";
cout<<"Address is(outside block):"<<ptr;//ptr is dangling pointer(same address)
       ptr=NULL;//Solution to dangling pointer(assign null address)

}
