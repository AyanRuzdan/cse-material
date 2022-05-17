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
```
#include<iostream>
using namespace std
int main()
	{
		cout << "Hello World!" ;
		return 0;
	}
```
or the same code can be written as, 
```
#include<iostream>
int main()
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
```
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
```
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
```
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
```
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
### Structure
Structures are derived data types.  
