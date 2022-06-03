#include <iostream>
#include <string>       //for strcpy(), etc
using namespace std;
class string1             //user-defined string type
   {
   private:
      char* str;                    //pointer to string
   public:
      string1(char* s)               //constructor, one arg
         {
         int length = strlen(s);    //length of string argument
         str = new char[length+1];  //get memory
         strcpy(str, s);            //copy argument to it
         }
      ~string1()                     //destructor
         {
         cout << "Deleting str\n";
         delete[] str;          //release memory
         }
         void display()           //display the String
         {
         cout << str << endl;
         }
   };
int main()
   {                     //uses 1-arg constructor
   string1 s1("This is DMA example for string");
   cout << "s1=";                   //display string
   s1.display();
   return 0;
   }



