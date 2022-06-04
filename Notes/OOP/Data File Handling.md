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
Contents of _new.txt_:
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
Contents of _new.txt_: 
```cpp
Semper Idem
```
Output:
```cpp
Semper Idem
```
### Detecting end-of-file
In order to keep on reading from a file, one has to make sure that the reading does not start from the end. And in order to check that, we check eof condition. We use:
```cpp
while(filein)
```
where _filein_ is an `ifstream` object which returns 0 value if any error occurs or end-of-file is encountered. We also use:
```cpp
if(fileIn.eof()!=0)
{
exit(1);
}
```
Here `eof()` is a member function of class _ios_. It returns _true_ if eof is encountered, and _false_ otherwise.
## File Modes
A file mode specifies the _mode_ in which the file will be opened. General form of `open()` with 2 arguments is:
```cpp
streamObject.open("filename", mode); //here mode can be any
```
Prototype of member functions contain default modes:
* `ios::in` for ifstream functions meaning open for reading only.
* `ios::out` for ofstream functions meaning open for writing only.
A few commonly used file modes are:

|Parameter|Meaning|
|-------|---------------------|
|ios:app|Append to end-of-file|
|ios::ate|Go to e.o.f on opening|
|ios::binary|Open in binary mode|
|ios::in|Open file for reading only|
|ios::nocreate|Error in opening if file does not exist|
|ios::noreplace|Error in opening if file already exists|
|ios::out|Open file for writing only|
|ios::trunc|To delete contents of the file|
Example for `append` mode:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[50];
	ofstream fileOut; //file output stream
	ifstream fileIn; //file input stream
	fileOut.open("new.txt", ios::app); //open file in append mode
	fileOut<<", Semper Supra."; //added required text
	fileOut.close(); //writing operations done, file closed
	fileIn.open("new.txt",ios::in); //file open in read-only-mode
	fileIn.getline(s,50); //get the first 50 characters in s-array
	cout<<s<<endl; //print the 50 characters from the file
	return 0;
}
```
Contents of _new.txt_ before append:
```cpp
Semper Idem
```
Contents after append:
```cpp
Semper Idem, Semper Supra.
```
### File pointers
Each file has two associated pointers to it, known as file pointers.
* Input Pointer/Get Pointer
* Output Pointer/Put Pointer
### Default File Actions
* In read only mode, the input pointer is automatically set at the beginning.
* In write only mode, the existing contents are deleted and output pointer is set at the beginning.
* In append mode, the output pointer moves to the end of file.

## File Manipulators
These are used to move file pointer to any desired location in the file.

|Manipulator|Function|
|--------|------------------------------------------------|
|`seekg()`|Moves get pointer(input) to a specified location|
|`seekp()`|Moves put pointer(output) to a specified location|
|`tellg()`|Gives the current position of the get pointer|
|`tellp()`|Gives the current position of the put pointer|

Example of file pointer manipulator:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[30];
	ofstream fileout;
	fstream file;
	fileout.open("hello",ios::out);
	fileout<<"Hello World";
	fileout.close();
	file.open("hello",ios::in|ios::out);
	cout<<"Position of get pointer: "<<file.tellg()<<endl;
	cout<<"Position of put pointer: "<<file.tellp()<<endl;
	file.seekp(6); //put pointer seeked
	file.seekg(6); //get pointer moved
	cout<<"Position of get pointer after seek: "<<file.tellg()<<endl;
	cout<<"Position of put pointer after seek: "<<file.tellp()<<endl;
	file>>s;
	cout<<s;
}
```
Contents of file _hello_:
```cpp
Hello World
```
Output of program:
```cpp
Position of get pointer: 0
Position of put pointer: 0
Position of get pointer after seek: 6
Position of put pointer after seek: 6
World
```
### Specifiying the offset of the pointer
The arguments used to seek the pointer represent the actual positions in the file.
* `seekp(offset, refposition);`
* `seekg(offset, refposition);`

Refposition takes one of the three following values:
* `ios::beg`, start of the file
* `ios::cur`, current position of the pointer
* `ios::end`, end of the file

A few example cases for pointer seeks:

|Seek Call|Action|
|-|-|
|`fout.seekg(0, ios::beg)`|Go to start|
|`fout.seekg(0, ios::cur)`|Stay at the current position|
|`fout.seekg(0, ios::end)`|Go to end of file|
|`fout.seekg(m, ios::beg)`|Move to (m+1)th byte in the file|
|`fout.seekg(m, ios::cur)`|Go forward by m byte(s) from the current position|
|`fout.seekg(-m, ios::cur)`|Go backward by m byte(s) from the current position|
|`fout.seekg(-m, ios::end)`|Go backward by m byte(s) from the end|

### Sequential I/O Operations
* `put()` and `get()` is used to handle single character at a time.
* `write()` and `read()` functions are used to handle stream of data.

Example for `put()` and `get()`:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[80];
	cout<<"Enter a string: "; //Input=Return
	cin.getline(s,80);
	int len=strlen(s);
	fstream file;
	file.open("new.txt", ios::in|ios::out);
	for(int i=0;i<len;i++)
	{
		file.put(s[i]);
	}
	file.seekg(0);
	char ch;
	while(file)
	{
	file.get(ch);
	cout<<ch;
	}
	return 0;
}
```
Note: This program causes the last character to be repeated once.
Output:
```cpp
Returnn
```
### `write()` and `read()`
* `infile.read((char*)&V, sizeof(V));`
* `outfile.write((char*)&Vm sizeof(V));`

These functions take two arguments, first of address of variable V, second is length of variable in bytes.
For example:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	float height[4]={11.1, 12.5, 14.6, 6.9};
	ofstream outfile;
	outfile.open("abc");
	outfile.write((char*)height, sizeof(height));
	outfile.close();
	float q[4];
	ifstream infile;
	infile.open("abc");
	infile.read((char*)q, 32);
	cout<<q[0]<<" "<<q[1];
	return 0;
}
```
Output:
```cpp
11.1 12.5
```
## Reading and Writing Class Object
The binary input-output read() and write() are designed to read and write from disk file objects. These functions handle entire structures of an object as a single unit.Function `write()` copies a class object from memory byte-by-byte with **no** conversion.
## Error Handling Function
|Function|Return Value and Meaning|
|-|-|
|`eof()`|Returns true(non-zero) if end of file is encountered, otherwise return false(zero)|
|`fail()`|Returns true when an input or output operation fails|
|`bad()`|Returns true if an invalid operation is attempted or any unrecoverable error has occured|
|`good()`|Returns true if no error has occured|

## Codes provided by my prof.
