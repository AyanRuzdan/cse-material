#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
    fstream obj1;
    obj1.open("Destination.txt",ios::out);
    fstream obj2;
    obj2.open("Source.txt",ios::in);
    char ch;
    if(!obj1||!obj2)
    {
        cout<<"\n File could not be opened";
        exit(1);
    }
    ch=obj2.get();
    /*while(ch!=EOF)
    {
        obj1.put(ch);
        ch=obj2.get();
        
    }
    while(obj2)
    {
    	obj1.put(ch);
    	ch=obj2.get();
    }*/
    while(obj2.eof()==0)
    {
    	obj1.put(ch);
    	ch=obj2.get();
    }
    cout<<"\n Data copied from one file into another";
    return 0;

}
