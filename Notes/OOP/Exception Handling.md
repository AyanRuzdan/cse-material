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
---
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
---
### Multiple Catch Statements
* A single try statement can have many catch statements.
* Execution of a particular catch block depens on the type of exception thrown by the throw keyword.
* Multiple catch blocks are used when we have to catch a specific type of exception out of many possible type of exceptions.
* The catch block that matches with the type of exception thrown will be executed, while the rest of the catch blocks will be skipped.
General syntax:
```cpp
try
{
    //try block
}
catch(type1 arg)
{
    //catch block 1
}
catch(type2 arg)
{
    //catch block 2
}
...
...
...
catch(typeN arg)
{
    //catch block N
}
```
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
void test(int x)
{
    try
    {
        if(x==1) throw x;
        else if(x==0) throw 'x';
        else if(x==-1) throw 1.0;
        cout<<"End of try\n";
    }
    catch(char c)
    {
        cout<<"Caught a character\n";
    }
    catch(int m)
    {
        cout<<"Caught an integer\n";
    }
    catch(double d)
    {
        cout<<"Caught a double\n";
    }
    cout<<"End of try-catch system\n";
}
int main()
{
    cout<<"Testing multiple catches\n";
    cout<<"x==1\n";
    test(1);
    cout<<"x==0\n";
    test(0);
    cout<<"x==-1\n";
    test(-1);
    cout<<"x==2\n";
    test(2);
    return 0;
}
```
Output:
```cpp
Testing multiple catches
x==1
Caught an integer
End of try-catch system
x==0
Caught a character
End of try-catch system
x==-1
Caught a double
End of try-catch system
x==2
End of try
End of try-catch system
```
---
### Catching all exceptions
In some situations we may not be able to predict all possible type of exceptions and therefore may not be able to design independent catch handlers to catch them.
In such situations we can force a catch statement to catch all exceptions instead of a certain type alone; also known as _generic catch handler_
Catch all (or generic catch handler) should always be the last catch handler out of all available catch handlers.
General syntax:
```cpp
catch(...) //those 3 dots are actual syntax, see example
{
//all exceptions & statements for processing
}
```
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
void test(int x)
{
    try
    {
        if(x==0) throw x;
        if(x==-1) throw 'x';
        if(x==1) throw 1.0;
    }
    catch(...)
    {
        cout<<"Caught an exception\n";
    }
}
int main()
{
    cout<<"Testing generic catch\n";
    test(-1);
    test(0);
    test(1);
    return 0;
}
```
Output:
```cpp
Testing generic catch
Caught an exception
Caught an exception
Caught an exception
```
---
### Catching class type as an exception
We can also throw class types or user defined types from try block and design a suitable catch block for the same with an argument of class type.
For example:
```cpp
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class error
{
    int err_code;
    char *err_desc;
    public:
    error(int c, char *d)
    {
        err_code=c;
        err_desc=new char[strlen (d)];
        strcpy(err_desc, d);
    }
    void err_display(void)
    {
        cout<<"Error code: "<<err_code<<" Error description: "<< err_desc;
    }
}; 
int main()
{
    try
    {
        cout<<"Press any key:\n";
        getch();
        throw error(99, "test exception");
    }
    catch(error e)
    {
        cout<<"Exception caught successfully\n";
        e.err_display();
    }
    return 0;
}
```
Output:
```cpp
Press any key:
Exception caught successfully
Error code: 99 Error description: test exception
```
---
### Rethrowing an exception
If a catch block cannot handle the particular exception it has caught, then we can rethrow the exception to the next catch block for further handling.
Rethrowing causes the current exception to be thrown to the next enclosing `try/catch` sequence and is caught by a `catch` statement given after that enclosing `try` block. 
In such situations we can invoke `throw` directly, like 
```cpp
throw;
```
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
void divide(double x, double y)
{
    cout<<"Inside function\n";
    try
    {
        if(y==0.0)
        throw y; //first throw
        else
        cout<<"Division: "<<x/y<<endl;
    }
    catch(double)
    {
        cout<<"Caught double inside function\n";
        throw; //rethrow, goes to the main function catch
    }
}
int main()
{
    cout<<"Inside main()\n";
    try
    {
        divide(10.5,2.0);
        divide(20.0,0.0);
    }
    catch(double)
    {
        cout<<"Caught double inside main()\n";
    }
    cout<<"End of main()\n";
    return 0;
}
```
Output:
```cpp
Inside main()
Inside function
Division: 5.25
Inside function
Caught double inside function
Caught double inside main()
End of main()
```
---
### Key points with respect to Exception Handling
1. Implicit type conversion does not happen for primitive types. For example, in the following program, 'b' is not implicitly converted to int.
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    try
    {
        throw 'b';
    }
    catch(int x)
    {
        cout<<"Caught"<<x;
    }
    catch(...)
    {
        cout<<"Default Exception\n";
    }
    return 0;
}
```
The output will be
```cpp
Default Exception
```
and not
```cpp
Caught x
```
2. If an exception is thrown and not caught anywhere, the program terminates abnormally, for example, in the following program an int is thrown, but there is not catch block to catch an int.
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    try
    {
        throw 10;
    }
    catch(char a)
    {
        cout<<"Caught";
    }
    return 0;
}
```
Output:
```cpp
terminate called after throwing an instance of 'int'
```
3. In C++, the try-catch block can be nested
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    try
    {
        try
        {
            throw 20;
        }
        catch(int n)
        {
            cout<<"Handled partially\n";
            throw; //rethrow
        }
    }
    catch(int n)
    {
        cout<<"Handled remaining part";
    }
    return 0;
}
```
Output:
```cpp
Handled partially
Handled remaining part
```
4. If there are statements after throw, and exception has been thrown, then those statements will not execite, as control will be shited to catch block.
5. When an ecxeption is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.
```cpp
#include<bits/stdc++.h>
using namespace std;
class Test
{
    public:
    Test()
    {
        cout<<"Constructor\n";
    }
    ~Test()
    {
        cout<<"Destructor\n";
    }
};
int main()
{
    try
    {
        Test t1;
        throw 10;
    }
    catch(int i)
    {
        cout<<"Caught "<<i<<endl;
    }
    return 0;
}
```
Output:
```cpp
Constructor
Destructor
Caught 10
```
---