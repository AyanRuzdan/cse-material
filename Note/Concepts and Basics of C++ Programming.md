# Unit 1
### Introduction to CPP
 C++ was an extension to C language and was developed by Bjarne Stroustrup at Bell Labs.  
 It is a general purpose language and is mostly used for Competitive Programming these days.
### Differences between POP and OOP
|Features|POP|OOP|
|-|-|-|
|Divided into|Program is divided into Functions|Program is divided into objects|
|Importance|Not to data but to sequence|Importance to data and not on procedures and functions|
|Approach|Top Down|Bottom Up|
|Access Specifier|None|Public, Private, Protected|
|Data Moving|Data moves from function to function|Objects move through member functions|
|Data Access|Global Data Sharing|Access is controlled|
|Data Hiding|POP is less secure|OOP is more secure|
|Overloading|Not Possible|Function and Operator Overloading is possible|
|Examples|C, FORTRAN, Pascal|C++, C#, Java|
### Features of I/O Streams
#### Header Files
Header files contain predefined function libraries, which can be used by users for their use. We use iostream for console input and output.
#### `using namespace std`
>A namespace is designed and used as additional information to differentiate between similar functions, classes and variables etc. with the same name available for different libraries. Using namespace one can define the context in which names are defined. In essence, a namespace defines a scope.  

Namespaces can be used initially in the program like `using namespace std` or as prefix to the identifier with scope resolution operator (`::`) like,  
```cpp
#include<iostream>
using namespace std
int main()
{
    cout << "Hello World!" ;
    return 0;
}
```
or the same code can be written as, 
```cpp
#include<iostream>
int main()
	{
		std::cout << "Hello World!" ;
		return 0;
	}
```  
```cpp
{
    std::cout << "Hello World!" ;
    return 0;
}
```
### Reading and Writing Data
Two operators are required for this, `cout` and `cin`.  
`cout` is a predefined **object**(remember this) and represents the standard output stream.  
`<<` is called as the _**insertion operator**_.  
`cin` is also a predefined **object**(remember this) and represents the standard input stream.  
`>>` is called as the _**extraction operator**_.
An example I/O code is:
```cpp
#include<iostream> //this is the header inclusion
using namespace std //this is the namespace
int main() //this is where the program begins execution from
{
    int x; //x variable is declared
    cin >> x ; //the value of x is taken as input
    cout << x ; //the input value of x is now output on the screen
    return 0; //tells that the program ran with no errors
}
```
### Classes and Objects (Overview)
In C++, rather than creating separate variables and functions, we can also wrap these related data and functions in a single place. This programming paradigm is called **object-oriented programming**.  
#### Class
A class is a building block, that leads to OOP. It is a **_user-defined_** data type, which holds its own **data members** and **member functions** which can be accessed and used b creating an instance of that class.
##### Creating a class
A class is defined by the keyword `class` followed by the class name. A class contains everything within curly braces and is terminated by a semicolon (`;`). For example,  
```cpp
class Car
{
    //objects inside the class
};
```
#### Object
An **object** is an _instance_ of a class. When a class is defined, no memory for object is allocated, but only when it is instantiated.
We can create and object like this way: `ClassName ObjectName;`. 
#### Accessing a data member
Access of a data member solely depends on the access control of the member. If its `public`, then the data member can be directly accessed using the member access (`.`) operator with the class object.
##### Access Specifiers
C++ has three access specifiers
* `public`
* `private`
* `protected`
1. The `public` access specifier allows a class to **show** its member variables and members functions to other functions and objects.
2. The `private` access specifier allows a class to **hide** its member variables and members functions to other functions and objects. Also known as the **_Default Access Specifier_** for a class.
3. The `protected` access specifier also works the same as `private`, but its members can be accessed using inheritance.
##### Demonstration of `public` access
```cpp
//To find area of a circle
#include<bits/stdc++.h>
using namespace std;

class Circle
{
    public: //access specifier
    double radius;
    double area()
    {
        return 3.14 * radius * radius;
    }
};
	
int main()
{
    Circle obj; //class object
    obj.radius = 7; //accessing public member outside class using dot operator
    cout << "Radius is: " << obj.radius << "\n" ;
    cout << "Area is: " << obj.area() ;
    return 0;
}
```
#### Demonstration of `private` specifier and its limitation
```cpp
#include<iostream>
using namespace std;

class Circle
{
    private:
        double radius;
    public:
        void area(double r)
        {
            radius = r;
            double area = 3.14 * radius * radius;
            cout << "Radius: " << radius << endl; //endl can be used in place of "\n"
            cout << "Area: " << area;
        }
};
	
int main()
{
    Circle obj;
    obj.radius = 7;
    obj.area(2);
    return 0;
}
```
> The above code will not work and will give error because we are trying to access a `private` member outside of its class, which is not allowed.  

#### Difference between `public` and `private`
|`public`|`private`|
|-|-|
|All class members under `public` are available to everyone|Class members under `private` can be only accessed by functions inside the class|
|Data members and member functions declared `public` can be accessed by other classes also|Only the member functions or the **_friend function_** are allowed to access the private data members of the class|
|`public` members can be accessed anywhere using the (`.`) operator|`private` members cannot be accessed outside the class|
#### Methods of Member Function Definition in Class
There are two ways to define a function in class:
* Inside the class
* Outside the class using scope resolution operator. (`::`)  

Function definition inside the class is given as:
```cpp
class pqr{
	private:
	int x;
	public:
	void get_x(){
		cout<<"Enter the value of x. ";
		cin>>x;
	}
	void display_x(){
		cout<<"The value of x is: "<<x;
	}
};
```
Function definition outside the class is given as:
```cpp
class pqr{
	private:
	int x;
	public:
	void get_x();
	void display_x();
};
void pqr::get_x(){
	cout<<"Enter the value of x.";
	cin>>x;
}
void pqr::display_x(){
	cout<<"The value of x is: "<<x;
}
```
> **Note:** Size of an empty class in C++ is given as 1 byte. 
### Structure
Structures are derived data types. It is a group of data items of different data types held together under a single unit. _It is a collection of heteregenous elements._ We make structures in the following manner:  
```cpp
struct Name{ //structure Name can be anything
	type Name1;  //here type could be any
	type Name2;
	type Name3;
};
```
>**Note:** A structure does not **reserve** space in memory. Instead it creates a new data type used to define structure variables.

Structure variables are defined either out of class by `structureName varName` or at the end of the structure definition like, 
```cpp
struct Name
{
	type Name1;
}structVariable1;
```
It is at **this** point that memory is set aside for the variable.
> **Note:** In a structure, variables are stored in a contiguous manner in the memory in the order in which they are declared.

### Union
* A union is similar to a structure.
* The difference is that in a structure each member has its own memory location, but in union the same memory is shared by all members.
* It also takes less space than a structure.
* It can also contain many data members of different types, but can handle only one member at once.
* It is declared using the keyword `union`.
Example:
```cpp
union books{
	int code;
	char name;
	float price;
}novel; //don't forget the semicolon
```
>**Note**: A union allocates memory for the variable which requires the most amout of memory.

#### Difference between Structure and Union
|Structure|Union|
|-|-|
|Keyword `struct` is required|Keyword `union` is required|
|Compiler allocates memory for each member.|Memory is allocated by looking at the largest member.|
|Size of structure is greater than or sum of member size|Size of union is equal to largest member|
|Each member has a unique memory location|Memory allocated is shared by individual members of union|
|Address of each member is in ascending order|Address is same for all members|
|Change in one member value does not affect other members|Change in member value will affect other members|
|Individual members can be accessed at a time|Only one member can be accessed at a time|
|Several structure members can be initialised at once|Only the first member can be initialised|
#### A few differences between C and C++ Structures
* **Member functions inside structure**: C structures cannot have member functions inside themselves with data members, unlike C++.
* **Direct Initialization**: We cannot directly initialize data members in C, but we can do that in C++.
* **Using `struct` keyword**: Sounds a bit weird, but in C++, one can skip the use of the struct keyword. But it is compulsory in C.
* **Static Members:** Static members are not allowed in C.
* **Constructors:** C structures cannot have constructors inside them, unlike in C++.
* **sizeof operator (Very Imp.):** An empty structure in C has **_0_** size, but in C++ an empty structure has size of **_1_**.
* **Access modifier:** C has no access modifier, whereas C++ has three access modifiers.
### Enumeration
**Definition:** An _enumeration_ is a user defined data type consisting of a _set_ of named constant called enumerators.  
It is declared as `enum TypeName{val1, val2, val3...};`. An example code looks like this: `enum DaysOfTheWeek{sun, mon, tue, wed, thur, fri, sat};` and the order followed is _sun<mon<tue...<sat_.  
**By default the first enum has a value of _0_.**
> * **Note:** enum values are supposed to have valid identifier names and must not be enclosed within quotes.
> * enum values have an increasing order of _values_ unless explicitly declared in the code.  
For example, `enum numbers{one=1, twelve=12, thirty=30};` 

To use enum values we declare them using `TypeName varName;` for example `DaysOfWeek Holiday, TestDay, PracticalDay;`. And once an enum variable has been declared, we can associate them with the value of the enum set, like, `Holiday = sun; TestDay=tue; PracticalDay=wed;`
### Inline Functions
If a function is inline, the compiler places a _copy_ of the code of that function at each point where the function is called at compile time. In order to reduce overhead costs for function calling, they are instead expanded in line using inline functions. An example of inline function:
```cpp
#include<iostream>
using namespace std;
inline int Max(int x, int y){
	return (x>y)?x:y; //checks which value is larger using ternary operator
}
int main()
{
	cout<<Max(10,20);
}
```
#### Inline Member Functions
* The `inline` keyword must be used, but it can also be ignored if the function definition is more than 3-5 lines.  
* A function definition inside a class is by default inline
* A member function that is defined inside its class member list is defines as **inline member function**.
* Member function can also be declared outside using the `inline` keyword.  
Example:
```cpp
#include<iostream>
using namespace std;
class Calc{
	int x,y,add; //private by default
	public:
	void get(){ //inline member function
		cin>>x>>y;
	}
	public:
	void sum();
};
inline void Calc::sum(){ //inline function outside the class
	add=x+y;
	cout<<add;
}
int main(){
	Calc s; //class object
	cout<<"Inline function program";
	s.get(); //calling member function from the class body
	s.sum(); //calling inline function external to class
	return 0;
}
```
> **Note:** Inline is just a _request_, and not a _command_.
#### When is an inline function ignored 
A compiler will ignore inline requests for the following cases.
* If the function contains a loop.
* If the function has static variables.
* If the function is recursive.
* If the function does not return anything, even when a return statement is specified.
* If the function contains a switch or goto statement.
#### Advantages and Disadvantages of Inline Functions
* Advantage
  * Function call overhead does not occur.
  * Also saves overhead of a return call from a function.
* Disadvantage
   * Makes the program take up more memory.
   * Compile time overhead may increase if code is changed somewhere, causing compiler to recompile all calling locations.
   
 ### Static Data Members
 * It is initialised to _**0**_ when first object of its class is created and _**NO**_ other initialisation is permitted.
 * Only _**1**_ copy of that member is created for entire class and is shared by all objects.
 * It is visible only in class, but its lifetime in for entire program.
 * Type and scope must be defined _**outside**_ the class definition. It is necessary as static data members are stored separately as compared to class objects.
 * They are also known as _class variables_.

Example code for static data member:
```cpp
#include<iostream>
using namespace std;
class item{
	static int count;
	int number;
	public:
	void getdata(int s){
		number=s;
		count++;
	}
	void getcount(){
		cout<<count<<" ";
	}
};
int item::count; //definition of static member
int main(){
	item p,q,r;
	cout<<"Count ";
	p.getcount();
	q.getcount();
	r.getcount();
	p.getdata(12);
	q.getdata(36);
	r.getdata(108);
	cout<<"\nAfter reading ";
	p.getcount();
	q.getcount();
	r.getcount();
}
```
### Static Member Function
> **Note:** Static member function have access _only_ to static members declared in the _same_ class.

Static member functions can be called using the syntax: `className::functionName`.
Example code for static member function:
```cpp
#include<iostream>
using namespace std;
class Test{
    int code;
    static int count;
    public:
    void setcode(){
        code=++count;
    }
    void showcode()
    {
        cout<<"Code: "<<code<<endl;
    }
    static void showcount(){
        cout<<"Count: "<<count<<endl;
    }
};
int Test::count; //definition of static member
int main()
{
    Test t1,t2;
    t1.setcode();
    t2.setcode();
    Test::showcount();
    Test t3;
    t3.setcode();
    Test::showcount();
    t1.showcode();
    t2.showcode();
    t3.showcode();
    return 0;
}
```
## Codes Provided by my Prof.
#### Basic Class Object
```cpp
#include<iostream>
using namespace std;
class abc{
    int x,y;
    public:
    void getdata(){
        cout<<"Enter the values of x and y: ";
        cin>>x>>y;
    }
    void sum(){
        int z;
        z=x+y;
        cout<<"The sum of x and y is: "<<z;
    }
};
int main(){
    abc obj1;
    obj1.getdata();
    obj1.sum();
}
```
#### Basic Class Object and Member Function
```cpp

```
#### Arithmetic Operations with the help of Class
```cpp
#include<iostream>
using namespace std;
class arithmetic{
    int x,y;
    public:
    void getdata(){
        cout<<"Enter the value of x and y:"<<endl;
        cin>>x>>y;
    }
    void sum(){
        int z;
        z=x+y;
        cout<<"Sum is:"<<z<<endl;
    }
    void divide(){
        int z;
        z=x/y;
        cout<<"Integer Division result is:"<<z<<endl;
    }
    void multiply(){
        int z;
        z=x*y;
        cout<<"Multiplication result is:"<<z<<endl;
    }
    void subtract(){
        int z;
        z=x-y;
        cout<<"Subtraction result is:"<<z<<endl;
    }
};
int main(){
    arithmetic obj1;
    obj1.getdata();
    obj1.sum();
    obj1.subtract();
    obj1.multiply();
    obj1.divide();
}
```
#### Array of Objects
```cpp
#include<iostream>
using namespace std;
class employee{
    char name[50];
    int age;
    public:
    void getdata(void);
    void putdata(void);
};
void employee::getdata(void){
    cout<<"Enter the name of employee: ";
    cin>>name;
	cout<<"Enter the age of employee: ";
	cin>>age;
}
void employee::putdata(void){
    cout<<"Entered name is: "<<name<<endl;
    cout<<"Entered age is: "<<age;
}
const int size=3;
int main(){
	employee emp[size];
	int i;
	for(i=0;i<3;i++){
		cout<<"\nEnter details of employee number: "<<i+1<<endl;
		emp[i].getdata();
	}
	for(i=0;i<3;i++){
		cout<<"\nDetails of the employee number: "<<i+1<<endl;
		emp[i].putdata();
	}
	return 0;
}
```