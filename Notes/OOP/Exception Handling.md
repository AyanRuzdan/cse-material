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