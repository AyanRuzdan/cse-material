# Unit 1 (contd.)
## Functions
> **What is a function?**
> > _A function is self contained block of statements that perform a coherent task of some kind_.

We have two kind of functions:
* Built-in library functions
* User defined functions

Why use function?
* It helps to avoid to rewrite the same code again and again.
* Large programs can be reduced into smaller functions.
* It becomes easier to keep track of flow of program.

### Function Declaration and Definition
A function is declared by
```cpp
returnType funcName(dataType1, dataType2 ... dataTypeN)
``` 
A function definition is given by
```cpp
returnType funcName(dataType1 parameter1, dataType2 parameter2, ..., dataTypeN parameterN)
{
	function Body;
}
```
A function call is given by
```cpp
funcName(parameter1, parameter2, ..., parameterN)
```
### Function Prototype
A prototype statement helps the compiler to check the return type and arguments type of the function.
This is what a normal function looks like:
```cpp
#include<iostream>
using namespace std;
void sum(int, int); //function declaration, don't forget the semicolon
int main(){
    int x,y;
    cout<<"Enter two numbers: ";
    cin>>x>>y;
    sum(x,y); //function calling, these are the "actual" arguments
    return 0;
}
void sum(int a, int b){ //function definition, these are the "formal" arguments
    int c = a + b;
    cout<<"Sum of the two numbers is: "<<c;
} 
```
The output of this program will be:
```cpp
Enter two numbers: 13 19
Sum of the two numbers is: 32
```
### Default Arguments
In the function prototype declaration, the default values are provided. Whenever a call is made to function without specifying an argument, the program will automatically assign values to the parameters from the default arguments prototype.
For example:
```cpp
#include<iostream>
using namespace std;
int sum(int p, int q, int r=10, int s=15){
    return (p + q + r + s);
}
int main(){
    cout << sum(5, 10) << endl; //sum = 40
    cout << sum(5, 10, 15) << endl; //sum = 45
    cout << sum(5, 10, 15, 20) << endl; //sum = 50
    return 0;
}
```
## Manipulator Functions
> **What are manipulator functions?**
> > Manipulator functions are special stream functions that change certain characteristics of the input and output. They change the format flags and values for a stream. The main advantage of using manipulator functions is that they facilitate the formatting of input and output streams.

Here is a list of commonly used manipulator functions used in stream classes: 
* endl
* hex, oct, dec
* setbase
* setw
* setfill
* setprecision
* ends
* ws
> **Note:** Using header `iomanip` is compulsory to use a manipulator function.
### `endl`
The endl is an output manipulator to generate a carriage return or a line feed character. It may be used as many times as required in a given program. For example: `cout<<"Hello"<<endl<<"World";`, will give the output:
```cpp
Hello
World
```
### `setbase`
The setbase manipulator is used to convert the base of one numeric value into another base. The common bases used are: dex[10], hex[16] and oct[8]. For example:
```cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int x=200;
	cout<<x<<" in hexadecimal is: "<<hex<<x<<endl;
	cout<<setbase(10)<<x<<" in octal is: "<<oct<<x<<endl;
	cout<<setbase(10)<<x<<" in decimal is: "<<x<<endl;
}
```
The output will be:
```cpp
200 in hexadecimal is: c8
200 in octal is: 310
200 in decimal is: 200
```
### `setw`
The setw stands for setwidth. It is used to specify the minimum number of character positions on the output field a variable will consume. The general format is `setw(int w)`. The default value is _0_. For example:
```cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int x=200;
	cout<<setw(10)<<x;
}
```
The output will be:
```
_______200, where (_) means white space
```
### `setfill`
It is used to specify a different character to fill the unused field width of the value. The general syntax is `setfill(char w)`. The default fill character is _**white space**_. For example:
```cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int x=200;
	cout<<setfill('$')<<setw(20)<<x;
}
```
The output will be:
```cpp
$$$$$$$$$$$$$$$$$200
20 total characters
3 digits and 17 special characters replacing the white spaces that was given by setw(20)
```
### `setprecision`
It is used to control the number of digits of an output stream display of a floating point value. The general syntax is `setprecision(int p)`. The default precision count is _6_. For example:
```cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double x=22;
	cout<<setprecision(10)<<x/7<<endl;
	cout<<setprecision(15)<<x/7;
}
```
The output will be:
```cpp
3.142857143 (10 digits)
3.14285714285714 (15 digits)
```
### ends
It is used to attach a null terminating character `\0` at then end of a string. It takes no input and gives output of null character.
### ws
It is used to ignore the leading white space that precedes the first field.

---
## Function Scope Rules
### Local Variables
Local variables are defined inside the function body or in a compound statement. The **_scope_** of these variables are inside the function where they are defined. For example:
```cpp
int sum(int x, int y)
{
	int i, j, k; //these three variables have local scope and will be irrelevant outside the function block
}
```
### Global Variables
Global variables are variables whose scope is valid throughout the entire program. For example:
```cpp
int main(){
	int x; //valid in the entire program
	{
		int y; //valid only in block
	}
}
```
## Categories of Functions
> * No parameter & no return value
> * Parameter & no return value
> * Parameter & return value
> * No parameter but return value 

#### Function with no parameter and no return value
```cpp
#include<iostream>
using namespace std;
int main(){
    void print(); //func declaration
    cout<<"No parameter and no return value\n";
    print(); //func calling
}
//func definition
void print(){
    for(int i=1;i<=10;i++)
    {
        cout<<"*";
    }
}
```
The output will be:
```
No parameter and no return value
**********
```
#### Function with parameter but no return value
```cpp
#include<iostream>
using namespace std;
int main(){
    int a=10,b=20;
    void mul(int,int);
    mul(a,b); //actual arguments
}
// formal arguments
void mul(int x, int y){
    int s;
    s=x*y;
    cout<<"Value of mul() is "<<s; 
}
```
The output will be:
```cpp
Value of mul() is 200
```
#### Function with parameter and return value
```cpp
#include<iostream>
using namespace std;
int main(){
    int a=12, b=25, c;
    int max(int,int);
    c = max(a,b);
    cout<<"Greatest number is "<<c;
}
int max(int x, int y){
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
```
The output will be:
```cpp
Greatest number is 25
```
#### Function without parameter but return value
```cpp
#include<iostream>
using namespace std;
int main(){
    int sum();
    int c=sum(); //actual arguments
    cout<<"Sum is "<<c; 
}
int sum(){
    int x=1,y=2;
    return (x+y); //return value
}
```
The output will be:
```cpp
Sum is 3
```
## Overloading (A general discussion)
> **What is overloading?**
> * Overloading means assigning multiple meanings to a function name or operator symbol.
> * It allows multiple definition of function with same name, but different signatures.
> 
> C++ supports:
> * Function Overloading
> * Operator Overloading
> 
> **Why is overloading useful?**
> *  Function overloading allows functions that perform the same task on object of different types to be given the same name.
> * Operator overloading provides a convenient notation for manipulating user-defined objects with conventional operators.

## Function Overloading
It is the process of using the same name for two or more functions. It requires redefinition of a function to use a different function signatures, i.e.,
* Different _type_ of parameters
* Different _sequence_ of parameters
* Different _number_ of parameters

For example:
```cpp
#include<iostream>
using namespace std;
void sum(int,int);
void sum(double,double);
void sum(char,char);
int main(){
    int a=10, b=20;
    double c=7.52, d=8.14;
    char e='a', f='b' ; 
    sum(a,b);
    sum(c,d);
    sum(e,f);
    return  0;
}
void sum(int x, int y){
    cout<<"Sum of integers are: "<<x+y<<endl;
}
void sum(double x, double y){
    cout<<"Sum of two floating numbers are: "<<x+y<<endl;
}
void sum(char x, char y){
    cout<<"Sum of characters are: "<<x+y<<endl;
}
```
The output will be:
```cpp
Sum of integers are: 30
Sum of two floating numbers are: 15.66
Sum of characters are: 195 //here we get an integer sum of their ASCII values i.e. 97+98=195
```

## Friend Function
Data hiding is really important and a fundamental part of object-oriented programming. It restricts the access of private members outside of the class. Similarly, protected members can be only accessed by derived classes and are not accessible from outside the class. 
However, C++ provides us a feature which allows us to break this rule. It is called **_friend function_**. 
Friend function of a class:-
* Is defined outside the class scope.
* Is **_NOT_** a member function of the class. **(_Remember this_)**
* Has the right to access both _public_ and _non-public_ members of the class.
* Standalone functions and entire classes can be declared as friend of a class.
* Mostly used when a member function cannot do a specific function.

We declare friend function in the following way:
```cpp
class className{
	friend returnType functionName(arguments)
};
```
Some special things to be paid attention to about a friend function are:
* It is not in the scope of the class to which it is declared as a friend
* It _**cannot**_ be called using the object of that class.
* It is invoked like a normal function, without the help of any object.
* It cannot access members directly, and uses object name and dot membership e.g. (obj.A)
* It can be declared anywhere from private to public, its meaning doesn't change.
* Usually, it has objects as its arguments.

Example code for friend function:
```cpp
#include<iostream>
using namespace std;
class Test{
    int a,b;
    public:
    void set_value(){
        a=10;
        b=20;
    }
    friend float average (Test t);
};
float average(Test t){
    return float(t.a+t.b)/2;
}
int main()
{
    Test x;
    x.set_value();
    cout<<"Average: "<<average(x);
    return 0;
}
```
The output will be:
```cpp
Average: 15
```
### Adding two members of different classes using friend function
```cpp
#include<iostream>
using namespace std;
class B; //forward class declaration
class A{
    private:
    int a;
    public:
    void init_a(){
        a=10;
    }
    friend int sum(A,B); //forward friend declaration
}objA; //object of class A
class B{
    private:
    int b;
    friend int sum(A,B);
    public:
    void init_b(){
        b=20;
    }
}objB; //object of class B
int sum(A objectA, B objectB){ //(className objectName) as arguments
    int x;
    x=objectA.a + objectB.b;
    return x;
}
int main(){
    objA.init_a();
    objB.init_b();
    cout<<"Sum: "<<sum(objA,objB);
    return 0;
}
```
The output will be:
```cpp
Sum: 30
```
### A function friendly to two classes:
```cpp
# include<iostream>
using namespace std;
class ABC;
class XYZ{
    int x;
    public:
    void setvalue(int i){
        x=i;
    }
    friend void max(XYZ, ABC);
};
class ABC{ 
    int a;
    public:
    void setvalue(int i){
        a=i;
    }
    friend void max(XYZ, ABC);
};
void max(XYZ m, ABC n){
    if(m.x>= n.a)
    {
        cout<<m.x;
    }
    else
    {
        cout<<n.a;
    }
}
int main()
{
    ABC abc;
    abc.setvalue(10);
    XYZ xyz;
    xyz.setvalue(20);
    max(xyz,abc);
    return 0;
}
```
The output will be 
```cpp
20
```