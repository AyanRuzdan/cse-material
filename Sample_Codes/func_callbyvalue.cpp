#include <iostream>
using namespace std;
void swap(int, int);// function declaration
int main ()
{
   int a = 100;     // local variable declaration
   int b = 200;
   cout << "Before swap, value of a :" << a << endl;
   cout << "Before swap, value of b :" << b << endl<<endl;
   swap(a, b);    // calling a function to swap values
   cout << "After swap, value of a :" << a << endl;
   cout << "After swap, value of b :" << b << endl;
   return 0;
}
void swap(int x, int y)
{
   int temp;
   temp = x;   // save the value of x
   x = y;     // put y into x
   y = temp; // put x into y
   cout << "After swap, value of x(a) :" << x << endl;
   cout << "After swap, value of y(b) :" << y << endl<<endl;
}
