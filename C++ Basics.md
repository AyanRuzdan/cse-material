# Unit 1
 C++ was an extension to C language and was developed by Bjarne Stroustrup at Bell Labs.  
 It is a general purpose language and is mostly used for Competitive Programming these days.

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
cout<<"Hello World!";
return 0;
}
```
or the same code can be written as, 
```
#include<iostream>
int main()
{
std::cout<<"Hello World!";
return 0;
}
```