#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
   fstream FILE1,FILE2;
   char ch;
   FILE1.open("sourceappend.txt",ios::in);
   FILE2.open("appendfile.txt",ios::out);
   if(!FILE1||!FILE2)
   {
   cout<<"\n File could not be opened";
   exit(1);
   }
      ch = FILE1.get();
      while (ch != EOF)
       {
         FILE2.put(ch);
         ch=FILE1.get();
       }
      cout<<"File is merged with the content of another file";
      FILE1.close();
      FILE2.close();
      return 0;
}
