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
### setfill
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
### setprecision
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