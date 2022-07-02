# Unit 4 (contd.)
> Type conversion means converting a data type from one to another.

### Automatic Type Conversion
The C++ compiler does automatic type conversion to the data type that is more fitting.
There are 4 types of data conversion
* Basic to Basic
* Basic to Class
* Class to Basic
* Class to Class
### Basic to Basic
This is the type of conversion we normally see.
```cpp
int x;
float y=12.345;
x=y; //float is converted to int
```
---
### Basic to Class
It is done by the use of a constructor with one parameter. <br>
This constructor must be a member function of the class, and its parameters must of basic data type, which are to be converted.
```cpp
#include<bits/stdc++.h>
using namespace std;
class Time
{
    int hrs,min;
    public:
            Time(int t)
            {
                cout<<"Basic to Class Type Conversion\n";
                hrs=t/60;
                min=t%60;
            }
            void display()
            {
                cout<<hrs<<" : Hour(s)\n";
                cout<<min<<" : Minutes\n";
            }
};
int main()
{
    int duration;
    cout<<"Enter duration in minutes: ";
    cin>>duration;
    Time t1=duration;
    t1.display();
    return 0;
}
```
Output:
```cpp
Enter duration in minutes: 419
Basic to Class Type Conversion
6 : Hour(s)
59 : Minutes
```
---
### Class to Basic
We cannot use a constructor in this type of conversion. So we are supposed to define an _overloaded casting operator_ which can be usd to convert class type to basic type. It is known as conversion function.
The casting operator function should satisfy the following conditions:
1. It must be a class member.
2. It must not specify a return type.
3. It must not have any arguments.
```cpp
#include<bits/stdc++.h>
using namespace std;
class Time{
    int hrs,min;
    public:
            Time(int a,int b)
            {
                hrs=a;
                min=b;
            }
    operator int()
    {
        return (hrs*60 + min);
    }
};
int main()
{
    int h, m, duration;
    cout<<"Enter hours: ";
    cin>>h;
    cout<<"Enter minutes: ";
    cin>>m;
    Time t(h,m);
    duration=t.operator int();
    cout<<"Total minutes: "<<duration;
    return  0;
}
```
Output:
```cpp
Enter hours: 6
Enter minutes: 12
Total minutes: 372
```
---