#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
   fstream FILE1,FILE2;
   char ch1, ch2;
   char fname1[40], fname2[40];
   cout<<"Enter name of first file :";
   cin.getline(fname1,20);
   cout<<"Enter name of second file:";
   cin.getline(fname2,20);
   FILE1.open(fname1,ios::in);
   FILE2.open(fname2,ios::in);
   if(!FILE1||!FILE2)
   {
   cout<<"\n File could not be opened";
   exit(1);
   }
      ch1 = FILE1.get();
      ch2 = FILE2.get();
      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
       {
         ch1 = FILE1.get();
         ch2 = FILE2.get();
       }
      if (ch1 == ch2)
         cout<<"Files are identical";
      else if (ch1 != ch2)
         cout<<"Files are Not identical";
      FILE1.close();
      FILE2.close();
      return 0;
}
