# Unit 3 (contd.)
## Introduction
C++ provides a new technique for handling I/O operations throughh mecanisms known as streams.
A stream refers to a flow of data. It is classified into two categories:
> Input Stream
>> In input stream flow of data is from program-to-output device.
> Output Stream
>> In output stream the flow of data is from input device-to-program in main memory.
## Classes for file stream operations
The set of classes commonly used for I/O operations are:
* ifstrean
* ofstream
* fstream
These classes are derived from _fstreambase_ and corresponding _iostream_ class.
## Why to use files and file handling?
* It provides a convenient way to deal with large amounts of data.
* Data is stored permanently, unless file is not deleted.
* Helps to avoid typing data into programs by hand.
* File data can be shared between programs.
## Opening and Closing a File
Before opening a file, we need to decide four conditions for a given file:
* Name of file
* Data Type and Structure of file
* Purpose of opening the file (Editing/Reading)
* Opening method of file (Editable/Read-only)
### Filename conditions
* The filename should be a string of characters that is valid in the given operating system.
* The filename must have two parts, i.e. primary name and file extension.
### Opening a file
* For opening a file, we need to create a filestream first, and then link it to the filename.
* A filestream can be defined using the classes _ifstream_, _ofstream_ and _fstream_, all of which are contained in the header file _fstream_.
> A file can be opened in two ways:
> * Using a constructor function of the class
> * Using member function `open()` of the class.
### Opening a file using constructor
A constructor is used to initialize an object while it is being created. In this case, a filename is used to initialize the file stream object. It is done in two steps:
* Creating a filestream object to manage the stream using appropriate class.
* Initialize the file object with the desired filename.
For example:
```cpp
ofstream outFile("records");
```
This will create _outFile_ as an `ofstream` object that manages the output stream. This statement will open the file _**records**_ and attach it to the output stream called _outfile_.
Similarly,
```cpp
ifstream inFile("records")
```
will create _inFile_ as in `ifstream` object and attache it to the file _**records**_ for reading data.
We can also use the same file for both reading and writing data. For example:
```cpp
//program 1 ...
ofstream outFile("records");
//program 2 ...
ifstream inFile("records");
```
**BUT** if we want to read and write in the same program, then we can use `.close()`. For example:
```cpp
//program writing operations taking place
outFile.close(); //file is closed here
ifstream inFile("records") //file is open again but only for reading
// program reading operations taking place
inFile.close(); //file reading is done
```
### Writing in a file
```cpp
//Writing content into the file using provided strings
#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream oFile("new.txt");
	oFile<<"visualstudiocode";
	oFile.close();
	return 0;
}
```
Output of the file _new.txt_
```cpp
visualstudiocode
```
### Reading from a file
```cpp
//This program does not take input after space, i.e., only first word
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[11];
	ifstream iFile("new.txt");
	iFile>>s;
	iFile.close();
	cout<<s;
	return 0;
}
```
Content of _new.txt_:
```cpp
Semper Idem
```
Output:
```cpp
Semper
```
### Opening file using `open()`
The general syntax is:
```cpp
fileStream StreamObject;
streamObject.open("filename");
```
For example:
```cpp
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	const int n=80;
	char s[n];
	ifstream fin;
	fin.open("new.txt");
	while(fin){
		fin.getline(s,n);
		cout<<s;
	}
	fin.close();
	return 0;
}
```
Content of _new.txt_: 
```cpp
Semper Idem
```
Output:
```cpp
Semper Idem
```