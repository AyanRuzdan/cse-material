# Unit 6
## Exception
> Exception are the run-time anomalies or unusual conditions that a program may encounter while executing. For example: divide by zero, access of array outside the bound, or running out of memory space.
> Because exceptions are supposed to be outside the normal operation of a program, default action is to write out an error message and terminate the offending process.

### Type of Exceptions
#### Synchronous Exceptions
These are the type of exceptions for which error handling could be written under the control of the program. Errors such as _out of range_ and _overflow_ are synchronous type of exceptions.
#### Asynchronous Exceptions
Errors that are caused by events beyond the control of the program like keyboard interrupts, disk failure, hardware malfunctioning are called asynchronous exceptions.

> **Note:** Exception handling in C++ is designed to handle only synchronous exceptions.

### Exception Handling Mechanism
C++ provides an exception handling mechanism for dealing with exceptions raised during the program execution. It follows the following steps to deal with the exception:
1. Find the problem (_hit_)
2. Inform that an error has occurred (_`throw`_)
3. Receive the error information (_`catch`_)
4. Take action (_handle_)
There are specialised keywords in C++ for this purpose:
* `try`: It represents the block of code that can throw an exception.
* `catch`: Represents the block of code that is executed when a particular exception is thrown.
* `throw`: Used to throw an exception. Also used to list the exceptions that a function throws, but doesn't handle itself.
**_try block_**: A block of statements which may generate exceptions. 
When an exception is detected, it is thrown using a _`throw`_ statement in the try block.
A **_catch block_** defined by the keyword _`catch`_ catches the exception thrown by the throw statement in the try block and handles it accordingly.
> **Note:** The catch block that catches the/an exception must immediately follow the try block that throws the exception.

General syntax for exception handling:
```cpp
try
{
	throw exception; //exception detection and throw
}
catch(type arg)
{
// exception handling code
}
```
For example #1:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter the values of a & b: ";
    cin>>a>>b;
    int x=a-b;
    try
    {
        if(x!=0)
        {
            cout<<"Result is a-b: "<<x<<endl;
        }
        else
        {
            throw(x);
        }
    }
    catch(int i)
    {
        cout<<"Exception caught: (a-b)="<<x<<endl;
    }
    cout<<"End of main";
    return 0;
}
```
Output:
```cpp
//if there is no exception
Enter the values of a & b: 24 10
Result is a-b: 14
End of main
//if exception exists
Enter the values of a & b: 7 7
Exception caught: (a-b)=0
End of main
```
Example #2:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5]={3,1,4,1,6};
    try
    {
        int i=0;
        while(1)
        {
            cout<<a[i]<<" ";
            i++;
            if(i==5)
            throw i;
        }
    }
    catch(int j)
    {
        cout<<"\nArray is out of bounds at index "<<j;
    }
    return 0;
}
```
Output:
```cpp
3 1 4 1 6 
Array is out of bounds at index 5
```
### Throw outside of try block
A user defined function can also throw an exception if its body contains such lines of code which may behave abnormally on giving certain set of inputs.
In that case, throw keyword can be used inside the body of user defined function and it will be written for the condition which may cause the exception.
This is the case where throw keyword is used outside of try block, i.e. function definition.
User defined function will be called inside try block, and if it throws the exception, then suitable catch block will handle the exception.
```cpp
type function(arg_list) //function with exception
{
throw(object); //throws exception
}
try
{
//function invoke inside try
}
catch(type arg) //exception catching
{
//exception handling
}
```
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
void divide(int x, int y, int z)
{
    cout<<"Inside the function\n";
    if((x-y)!=0)
    {
        int r=z/(x-y);
        cout<<"Result: "<<r<<endl;
    }
    else
    {
        throw(x-y);
    }
}
int main()
{
    try
    {
        cout<<"Inside try block\n";
        divide(10,20,30);
        divide(10,10,20);
    }
    catch(int i)
    {
        cout<<"Exception Caught\n";
    }
    return 0;
}
```
Output:
```cpp
Inside try block
Inside the function
Result: -3
Inside the function
Exception Caught
```
### Multiple Catch Statements