## Microservices
Microservices architecture is a modern software design pattern where applications are built as a collection of loosely coupled, independently deployable services. This approach enhances scalability, flexibility, and maintainability compared to monolithic architecture.
### What are Microservices?
Microservices break down an application into small, independent services that communicate through APIs. Each service focuses on a specific functionality, such as authentication, payment, or inventory management.
### Characteristics of Microservices
- **Independently Deployable** – Each service can be deployed without affecting others.
- **Loosely Coupled** – Services interact via APIs rather than direct dependencies.
- **Domain-Driven Design** – Each service is aligned with a specific business function.
- **Polyglot Technology** – Different services can use different programming languages and databases.

### Microservices Communication

#### Synchronous Communication

- **REST APIs (HTTP)** – Services expose endpoints that other services can call.
- **GraphQL** – Fetches specific data in one request, reducing over-fetching.
- **gRPC** – Uses Protocol Buffers (Protobuf) for efficient, low-latency communication.

#### Asynchronous Communication

- **Message Queues** (RabbitMQ, Apache Kafka, AWS SQS) – Services publish messages that others consume.
- **Event-Driven Architecture** – Services react to events instead of direct requests.

### Key Components of a Microservice System

- **API Gateway** – Acts as a single entry point for client requests, routing them to appropriate services.
- **Service Discovery** – Helps services find each other dynamically.
- **Load Balancer** – Distributes traffic across multiple instances of a service.
- **Containerization and Orchestration** – Docker for packaging, Kubernetes for managing deployments.

### Logging and Monitoring

---

## C++ References

- [Learn C++](https://www.learncpp.com/)
- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Tutorial](https://www.cplusplus.com/doc/tutorial/)

### What is C++?

C++ is a programming language that focuses on runtime speed and functionality.

- It is a **compiled language**, unlike Python, which is an **interpreted language**.
- It is a **mid-level programming language**, though many consider it closer to low-level.
- If **C++ is mid-level**, then **Python is high-level**, and **Assembly is low-level**.

### Advantages of C++

- Very widely used and supported.
- Many libraries are available.
- Resulting code is very fast.
- Syntax is similar to Java and other mid-level languages.
- C++ programmers are in high demand.
- Code is highly customizable.
- C++ will be around for a long time.

### Disadvantages of C++

- Easy to write unsafe code, leading to crashes.
- Must manage memory manually.
- Syntax can be a little confusing.
- Hard to read others’ code due to custom definitions/operator overloading.
- Compiler/linker errors can be difficult to interpret.

### C++ Programming Language

- **Created by:** Bjarne Stroustrup (Bell Labs)
- **Originally called:** “C with Classes” → Renamed to **C++ in 1983**
- **Procedural superset of C** (with exceptions)
- Supports **object-oriented programming** and **generics**
- Maintains the **efficiency of C**
- Very popular in **video game development**
- Influenced the development of **C# and Java**

### C++ Versions

- **First appeared:** 1985
- **C++98** – First standardized version
- **C++11** – Many new features and quality-of-life improvements
- **C++14, C++17, C++20** – Further enhancements

### C++ Properties

- **C++ is statically typed**
    
    - Variables must be defined and typed before use:
        
        ```cpp
        int year = 2018;
        ```
        
    - Similar to Java and C, where types are defined at compile time.
- **Python is dynamically typed**
    
    - Variable types are defined at runtime:
        
        ```python
        num = 10
        ```
## Your first C++ Program
```cpp
#include <iostream>
```
- The first line is a pre-processor directive (more about pre-processor later)
- It is used to include a C++ library
- This particular library is used for input/output streams
- It will let us use std::cout to print onto the console
```cpp
int main(int argc, char * argv[])
```
- Each C++ program must have a main function which is run when program starts
- Contents of the function is enclosed in `{}`
- Main function has int return type
- `argc` is the number of program arguments
- `argv` is the array of `string (char *)` arguments
	- Very similar to Java's `main(string args[])`
```cpp
std:: cout << "Hello, world!\n" ;
```
- This line prints string "Hello, world!\n"
- `std` is a namespace that contains the `cout` output stream
- The `<<` operator 'pipes' the string to `cout`
- Can be used to print any base C++ type
- Each C++ statement must end in `;`
- C++ is case sensitive
```cpp
return 0;
```
- Main has a return type of `int`
- Return 0 if program ran to normal end
- Return something else if there is an error
	- Used by other programs to detect errors
- Program may compile/run without this, but it is highly recommended to use it
## C++ Whitespace
For the most part, it does not matter
```cpp
std::cout                 <<           "Yo"        ;
```
```cpp
int add(int x, int y){ return (x+y);}
int add(int x, int y){
return (x + y);
}
```
But we cannot separate strings with whitespaces into next lines
```cpp
std::cout << "Hello
World" << std::end; // This will not work
```
## C++ Indentation
Allman style uses braces in a new line, like:
```cpp
while(true)
{
	// your code goes here
}
```
Meanwhile this is the Stroustrup style:
```cpp
while(x == y){
// your code goes here
}
```
The Allman style is much preferred when using nested statements, as the indentation shows hierarchy in a much better way