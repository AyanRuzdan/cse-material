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
