#include<iostream>
using namespace std;
int main()
{
    string str="welcome";
    string str1;
	cout << "Size = " << str.size() << endl;
	cout << "Length = " << str.length() << endl;
	cout << "Max Size = " << str.max_size() << endl;
	cout << "Empty:  "<< (str1.empty() ? "yes" : "no") << endl;
    return 0;
}
