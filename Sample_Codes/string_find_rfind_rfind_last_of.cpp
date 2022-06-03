#include<iostream>
using namespace std;
int main()
{
   string s1 = "arlcome";
   string s2 = "wearweea";
   cout<<s2.find("wear")<<endl;
   cout<<s2.rfind("we")<<endl;
   cout<<s2.find_last_of('e')<<endl;
   cout<<s2.find_first_of('e')<<endl;
   cout<<s2.at(0)<<endl;
   s1.swap(s2);
   cout<<s1<<" "<<s2<<endl;
   s2.resize(3);
   cout<<s2;
   return 0;
}
