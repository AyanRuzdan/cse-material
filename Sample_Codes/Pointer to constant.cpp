//Pointer to constant
#include<iostream>
using namespace std;
int main()
{
	int var1 = 60, var2 = 0;
    const int *ptr = &var1;
    ptr = &var2;
    cout<<*ptr;
    //*ptr=*ptr+1;//Error
}
