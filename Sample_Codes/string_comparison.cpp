#include<iostream>
using namespace std;
int main()
{
   string s1 = "acme";
   string s2 = "zbcrome";
   cout<<s1.compare(s2)<<endl;
   cout<<s1.compare(2,2,s2,5,2)<<endl;
   cout<<s1.compare(2,2,s2);
   return 0;
}
