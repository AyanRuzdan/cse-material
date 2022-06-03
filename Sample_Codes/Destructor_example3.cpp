#include<iostream>
#include<string.h>
using namespace std;
class String
{
private:
	char *s;
	int size;
public:
	String(char *); // constructor
	~String();	 // destructor
};
String::String(char *c)
{
	size = strlen(c);
	s = new char[size+1];
	strcpy(s,c);
	cout<<"\nString is:"<<s;
}
String::~String()
{
	delete []s;
	cout<<"\n Memory freed which was allocated dynamically(Avoiding memory leak)";
}
int main()
{
    String obj1("Hello");
    return 0;
}
