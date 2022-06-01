# Unit 3
## Constructor
> It is a special member function having same name as that of its class which is used to initialise data members of class.

Some key points regarding a constructor:
* It has the same name as that of the class to which it belongs.
* It is executed automatically when a class is created.
* _A constructor has not return type, not even void._ 
* More than one constructor can be declared. It is called **constructor overloading**.
* A compiler generally declares a _default constructor_ if a constructor is not explicitly declared. (It has no parameters and has an empty body.)
* A constructor can be used for initialisation, but not for i/o operations.

> **A constructor should be declared in the public section of the class. If not declared in public section, then the entire class will become private. By doing this the object of the class cannot invoke the constructor from outside., which is the first member function to be executed automatically.**

General constructor syntax:
```cpp
class className
{
	public:
	className (parameterList)
}; //parameter list is optional
```
Example for constructor:
```cpp
#include<bits/stdc++.h>
using namespace std;
class Rectangle{
	private:
	int length, breadth;
	public:
	Rectangle(){
		length = 3, breadth = 10;
	}
	int area(int a, int b){
		int q = length * breadth;
		cout<<"Area is "<<a;
		return 0;
	}
};
int main()
{
	Rectangle r1;
	r1.area(4, 5);
	//arguments can't be left empty, even though the answer still be 30, not 20
	return 0;
}
```
The output will be:
```cpp
Area is 30
```
---
### Parameterized Constructor
In order to initialize various data elements of different objects with differnt value, we can pass arguments to a specific type of constructor. The constructor that can take arguments is called _**Parameterized Constructor**_.
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
class Rectangle{
	private:
	int length, breadth;
	public:
	Rectangle(int a, int b){
		length=a, breadth=b;
	}
int area(){
	int q=length*breadth;
	cout<<"Area is "<<q;
	return 0;
	}
};
int main(){
	Rectangle r1(5,6);
	r1.area();
	return 0;
}
```
The output will be:
```cpp
Area is 45
```
---
### Multiple Constructor
A class can have multiple constructor with different signatures.
```cpp
class rectangle{
	private:
	float height;
	float width;
	int xpos;
	int ypos;
	public:
	rectangle(){
		xpos = 0;
		ypos = 0;
	}
	rectangle(float, float); // constructor
	void draw(); // draw member function
	void posn(int, int); // position member function
	void move(int, int); // move member function
};
rectangle::rectangle(float h, float w){
	height = h;
	width = w;
}
```
---
### Constructor with default arguments
Just like functions, constructors can also have default arguments. In this case, if we don't pass values, then the constructor makes us of the default values provided.
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
class Rectangle{
	int length,breadth;
	public:
	Rectangle (int x=12,int y=30){ //default arguments
		length=x;
		breadth=y;
	}
	int area(){
		return(length*breadth);
	}
};
int main(){
	Rectangle r1;
	cout<<"Area is "<<r1.area();
	Rectangle r2(45,20);
	cout<<"\nArea is "<<r2.area();
	return 0;
}
```
The output will be:
```cpp
Area is 360 //12*30 default
Area is 900 //provided values
```
---
### Copy Constructor
A copy constructor creates a new object using an existing object of the same class and initialises each data member of newly created object with corresponding data member and existing object as passed argument.
> Since it creates a copy of an existing object, it is called a copy constructor.

For example:
```cpp
#include<iostream>
using namespace std;
class example{
	int x,y;
	public:
	example(int a,int b){
		x=a;
		y=b;
	}
	example(example &obj){
		x=obj.x;
		y=obj.y;
	}
	void display(){
		cout<<"\n Values of x and y are:"<<x<<" "<<y;
	}
};
int main(){
	example obj1(2,5);
	obj1.display();
	example obj2(obj1);//Copy Constructor is called
	obj2.display();
	example obj3=obj1;//Second way of calling copy constructor
	obj3.display();
	return 0;
}
```
The output will be:
```cpp
Values of x and y are: 2 5
Values of x and y are: 2 5
Values of x and y are: 2 5
```
---
### Initializer List
It is placed between the parameter list and opening braces of the body of the constructor.
> **Note:** When the constructor is declared inside and defined outside the class using scope resolution, then the member initialization list can only be specified within the constructor definition and not its declaration.

An initializer list allows initialization of data members at the time o the creatin which is more efficient as values are assigned before the constructor even starts execution.
For example 
```cpp
rectangle(int a, int b):length(a), breadth(b){...}
```
For example:
```cpp
#include<iostream>
using namespace std;
class Rectangle{
	int length, breadth;
	public:
	Rectangle (int x,int y):length(x),breadth(y){}
	int area(){
		return(length*breadth);
	}
};
int main(){
	Rectangle r(12,24);
	cout<<"Area is "<<r.area();
	return 0;
}
```
The output will be:
```cpp
Area is 288
```
---
## Destructor
It is a member function having same name as that of constructor but it is preceded by a tilde(~) symbol, and is executed _automatically_ when object of a class is destroyed.

Some key points regarding destructors:
> * It doesn't have a return type, not even void. And no arguments either.
> * There is only one destructor in class. Just one. No overloading.
> * A compiler will generate a default destructor if not explicitly provided.
> * It can be used to deallocate memory for object. (**Most important use**)
>> **Need for destructors:**
>> * To de-initialize the objects when they are destroyed.
>> * To clear memory space occupied by a data member.

General syntax for destructor is:
```cpp
class className{
	... //private data
	public:
	~className(); //destructor
};
```
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
class counter{
	int id;
	public:
	counter(int i){
		id=i;
		cout<<"Contructor of object with id: "<<id<<endl;
	}
	~counter(){
		cout<<"Destructor with id: "<<id<<endl;
	}
};
int main(){
	counter c1(1);
	counter c2(2);
	counter c3(3);
	cout<<"End of main\n";
	return 0;
}
```
The output will be:
```cpp
Constructor of object with id: 1
Constructor of object with id: 2
Constructor of object with id: 3
End of main
Destructor with id: 3
Destructor with id: 2
Destructor with id: 1
```
> **Note:** One very important thing to note, destructors are called in the opposite order as compared to the order in which their constructors are called.

---
## Codes provided by my Prof.
### Constructor Overloading
```cpp
#include<iostream>
using namespace std;
class abc_overloading
{
	int x,y;
	public:
	abc_overloading() {
		x=2;
		y=3;
	}
	abc_overloading(int a,int b){
		x=a;
		y=b;
	}
	void display(){
		cout<<"Values of x and y are:"<<x<<" "<<y<<endl;
	}
};
int main(){
	abc_overloading obj1;
	obj1.display();
	abc_overloading obj2(4,5);
	obj2.display();
	return 0;
}
```
Output:
```cpp
Values of x and y are:2 3
Values of x and y are:4 5
```
### Constructor with Default Arguments
```cpp
#include<iostream>
using namespace std;
class Student
{
	int roll_no;
	int marks;
	public:
	Student(){
		roll_no=0;
		marks=0;
	}
	Student(int r,int m=0){
		roll_no=r;
		marks=m;
	}
	void show_data(){
	cout<<"Roll no=:"<<roll_no;
	cout<<"\tMarks="<<marks<<endl;
	}
};
int main(){
	Student s1;
	s1.show_data();
	Student s2(3);
	s2.show_data();
	Student s3(5,98);
	s3.show_data();
	return 0;
}
```
Output:
```cpp
Roll no=:0      Marks=0
Roll no=:3      Marks=0
Roll no=:5      Marks=98
```
### Copy Constructor
```cpp
#include<iostream>
using namespace std;
class example{
	int x,y;
	public:
	example(int a,int b){
		x=a;
		y=b;
	}
	example(example &obj){
		x=obj.x;
		y=obj.y;
	}
	void display(){
		cout<<"\n Values of x and y are:"<<x<<" "<<y;
	}
};
int main(){
	example obj1(2,5);
	obj1.display();
	example obj2(obj1);//Copy Constructor is called
	obj2.display();
	example obj3=obj1;//Second way of calling copy constructor
	obj3.display();
	return 0;
}
```
Output:
```cpp
Values of x and y are:2 5
Values of x and y are:2 5
Values of x and y are:2 5
```
### Default Constructor (different from constr. with def. args.)
```cpp
#include <iostream>
using namespace std;
class abc_default{
	int x, y;
	public:
	abc_default(){
		x = 2;
		y = 3;
		cout <<"Data members are initialized\n";
	}
	void display(){
		cout <<"Values of x and y are: "<< x << " " << y;
	}
};
int main()
{
	abc_default obj1;
	obj1.display();
	return 0;
}
```
Output:
```cpp
Data members are initialized
Values of x and y are:2 3
```
### Destructor (Example 1)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Sample{
	private:
	static int num_objects;
	static int num_objects_destroyed;
	public:
	Sample(){
		num_objects++;
	}
	~Sample(){
	num_objects_destroyed++;
	}
	void show_data(){
	cout<<"Number of objects created:"<<num_objects<<endl;
	cout<<"Number of objects destroyed:"<<num_objects_destroyed<<endl;
	cout<<"Number of objects active:"<<num_objects-num_objects_destroyed<<endl;
	}
};
	int Sample::num_objects=0;
	int Sample::num_objects_destroyed=0;
	void my_func(){
	Sample s8,s9;
	s9.show_data();
	}
int main(){
	Sample s1,s2,s3;
	{
		s1.show_data();//Created:3,Destroyed:0,Active:3
		Sample s4;
		{
			Sample s5;
			s5.show_data();//Created:5,Destroyed:0,Active:5
		}
	}
	s3.show_data();//Created:5,Destroyed:2,Active:3//Leaving local scope
	my_func();//Created:7,Destroyed:2,Active:5
	s2.show_data();//Created:7,Destroyed:4,Active:3//Leaving function scope
	return 0;
}
```
Output:
```cpp
Number of objects created:3
Number of objects destroyed:0
Number of objects active:3
Number of objects created:5
Number of objects destroyed:0
Number of objects active:5
Number of objects created:5
Number of objects destroyed:2
Number of objects active:3
Number of objects created:7
Number of objects destroyed:2
Number of objects active:5
Number of objects created:7
Number of objects destroyed:4
Number of objects active:3
```
### Destructor (Example 2)
```cpp
#include<bits/stdc++.h>
using namespace std;
class String{
	private:
	char *s;
	int size;
	public:
	String(char*); // constructor
	~String(); // destructor
};
	String::String(char *c){
	size = strlen(c);
	s = new char[size+1];
	strcpy(s,c);
	cout<<"String is: "<<s<<endl;
	}
	String::~String(){
	delete []s;
	cout<<"Memory freed which was allocated dynamically(Avoiding memory leak)";
	}
int main(){
	String obj1("Hello");
	return 0;
} //it is unethical to convert string to char*, but the code will work anyway
```
Output:
```cpp
String is: Hello
Memory freed which was allocated dynamically(Avoiding memory leak)
```
---