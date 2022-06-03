#include<iostream>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int *p1,*p2;
	int *x;
	int a=2;



	x=&a;
	p1=arr;
	p2=p1+6;//Adding a constant to a pointer(Pointer will point to 7(array element))
	p2=p2-2;//Subtracting a constant from a pointer(Pointer will point to 5(array element))
	cout<<p2-p1<<endl;//Subtracting two pointers(Returns 4(no. of elements)(Pointers pointing to the same array)
	while(p1<=p2)
	{

		cout<<*p1<<endl;//Comparison of two pointers (Pointers pointing to the same array)
		p1++;
	}
	cout<<x<<endl;
	x++;//Incrementing pointer by 1--Pointer moved by 1
	cout<<x<<endl;//It will give address of next location
	return 0;
}
