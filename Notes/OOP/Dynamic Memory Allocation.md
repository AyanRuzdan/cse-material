# Unit 5
## Allocation of Memory
### Static (or compile time memory) Allocation
* Allocation of memory space at compile time, e.g. `int a, int x[12];`
* During compile time a fixed amount of memory is reserved which cannot be changed during execution.
* This way unused memory is wasted, and if extra memory is required then it cannot be allocated.
* **This memory is allocated from stack.**

### Dynamic (or run time memory) Allocation
* Allocation of memory at run time with the help of `new` and `delete` operators.
* Helps us to allocate the amount of memory which is actually required during run time, no memory is wasted and sufficient amount of memory is allocated.
* **This memory is allocated from heap.**
---
It can be done with the help of new operators. 
The general syntax is:
```cpp
//for one memory location
data_type *ptr_name=new ;
//for array of memory
data_type *ptr=new data_type[size];
```
For example:
```cpp
//for single int
int *point = new int;
//for integer array
int *ptr = new int[10];
```
`new` returns address ofmemory location which then gets taken by the pointer.
> If compiler is unable to allocate memory, then NULL is returned.

General syntax for deallocation:
```cpp
//for single memory
delete pointer_name;
//for array of memory
delete[] pointer name;
```
### Memory Allocation Failure
Memory allocation failure may take palce in a situation when the system is unable to allocate sufficient memory as per the request of the program.
When this happens, the `new` operator will assign `NULL` to the pointer, indicating that the system was unable to allocate the requested memory.
For example:
```cpp
data_type *p = new data_type;
//or
data_type *p = new data_type[size];
if(!p)
{
	cout<<"Memalloc failure";
	exit(1);
}
//or
if(p==NULL)
{
	cout<<"Memalloc failure";
	exit(1);
}
```
#### Basic program to allocate and delete one memory location
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //using the two-line method to allocate memory
    int *p=NULL;
    p=new int;
    //checking for memalloc failure
    if(p==NULL)
    {
        cout<<"Memory Allocation Failure\n";
        exit(1);
    }
    else
    {
        cout<<"Memory allocated\n";
        *p=12;
        cout<<"Integer value stored: "<<*p<<endl;
        delete p; //deallocation
        cout<<"Memory deallocated";
    }
    return 0;
}
```
Output:
```cpp
Memory allocated
Integer value stored: 12
Memory deallocated
```
#### General example of application of dma
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    float *p=new float;
    float *r=new float;
    float *t=new float;
    float *si=new float;
    cout<<"Enter principle, rate and time: ";
    cin>>*p>>*r>>*t;
    *si=(0.01)*(*p)*(*r)*(*t);
    cout<<"Simple interest is: "<<*si;
    //delete memory when it is not required anymore
    delete p,r,t,si;
    return 0;
}
```
Output:
```txt
Enter principle, rate and time: 2 4 6
Simple interest is: 0.48
```
#### Alloc/dealloc of memory array
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *arr;
    int size;
    cout<<"Enter array size: ";
    cin>>size;
    cout<<"Allocating array of size "<<size<<endl;
    arr=new int[size];
    //check for allocation problem
    if(arr==NULL)
    {
        cout<<"Problem in memory allocation.\n";
        exit(1);
    }
    else
    {
        cout<<"Memory allocation successful\n";
        cout<<"Enter array elements: ";
        for(int i=0;i<size;i++)
        {
            cin>>*(arr+i);
        }
        cout<<"Entered elements are: ";
        for(int i=0;i<size;i++)
        {
            cout<<*(arr+i)<<" ";
        }
    }
    cout<<endl;
    delete []arr; //dealloc for array
    cout<<"Memory dellocated";
    return 0;
}
```
Output:
```cpp
Enter array size: 5
Allocating array of size 5
Memory allocation successful
Enter array elements: 1 14 16 100 76
Entered elements are: 1 14 16 100 76 
Memory dellocated
```
#### Sum of elements using dma
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *arr,sum=0;
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Creating array of size: "<<size<<endl;
    arr=new int[size];
    //skipping allocation check
    //going directly to element assignment
    cout<<"Enter array elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>*(arr+i);
    }
    for(int i=0;i<size;i++)
    {
        sum=sum+*(arr+i);
    }
    cout<<"Sum of elements of the array is: "<<sum;
    //deallocate array memory
    delete []arr;
    return 0;
}
```
Output:
```cpp
Enter size of array: 5
Creating array of size: 5
Enter array elements: 1 3 5 8 12
Sum of elements of the array is: 29
```
---
### Memory leak
> * A memory leak may occur when the programmer may forget to dellocate a memory.
> * In this situation the system will assume memory is still under use.
> * If it keeps on happening the at one time the system may run out of memory and system crash may occur.
> * Solution: Always deallocate/delete the memory once its not required.

Example mistake where memory leak may occur:
```cpp
#include<bits/stdc++.h>
using namespace std;
void mem_leak()
{
    int *ptr = new int[10];
}
int main()
{
    mem_leak();
    return 0;
}
```
Fix for the above given code:
```cpp
#include<bits/stdc++.h>
using namespace std;
void mem_leak()
{
    int *ptr = new int[10];
    //deallocate using delete
    delete []ptr;
}
int main()
{
    mem_leak();
    return 0;
}
```
---
## Dangling Pointer
It is a type of pointer which is pointing towards such a memory location which has been already deleted or deallocated.
This way the pointer may point to a free memory and result in unpredictable behaviour in later stages.
It is better to assign a NULL value to the pointer once the memory has been deallocated.