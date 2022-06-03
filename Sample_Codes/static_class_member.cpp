
#include<iostream>
using namespace std;
class item
 {   static int count;
      int number;
     public:
     void getdata(int d)
	{   number = d;
    	    count++;
	}
   void getcount()
    {
cout<<count;
   }
};
int item :: count;  // definition of static data member
  main(){
item a,b,c;
a.getcount();
 b.getcount();
 c.getcount();

 a.getdata(100);
 b.getdata(200);
 c.getdata(300);

cout<<"\nafter reading";
 a.getcount();
b.getcount();
c.getcount();
}







