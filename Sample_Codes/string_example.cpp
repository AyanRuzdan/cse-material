 #include <iostream>
 #include <string.h>
 using namespace std;
   int main()
   {
   char* str = "Hello, this is dynamic memory allocation";
   int len = strlen(str);     //get length of str
   char* ptr;                 //make a pointer to char
   ptr = new char[len+1];     //set aside memory: string + '\0'
   strcpy(ptr, str);          //copy str to new memory area ptr
   cout << "ptr=" << ptr << endl;  //show that ptr is now in str
   delete[] ptr;              //release ptr's memory
   return 0;
   }
