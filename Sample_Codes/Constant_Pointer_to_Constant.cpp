//Constant Pointer to Constant
#include<iostream>
using namespace std;
int main()
{
	int var1 = 60, var2 = 0;
    const int * const ptr = &var1;
    //ptr = &var2;//Error
    cout<<*ptr;
    //*ptr=*ptr+1;//Error
}
