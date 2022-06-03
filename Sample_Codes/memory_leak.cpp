// Program with memory leak
#include <iostream>
using namespace std;
// function with memory leak
void mem_leak()
{
	int* ptr = new int[10];
    //delete [] ptr; //Solution to memory leak
}
int main()
{
	mem_leak();
	return 0;
}
