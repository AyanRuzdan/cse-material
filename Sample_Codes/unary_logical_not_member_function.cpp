#include<iostream>
using namespace std;
class overloading
{
int x,y;
public:
overloading(int a,int b)
{
x=a;
y=b;
}
/*void operator!()
{
x=!x;
y=!y;
}*/
friend void operator!(overloading);
/*void show_data()
{
cout<<"\n Values of x and y after logical not are:"<<x<<" "<<y;
}*/
};
void operator!(overloading obj1)
{
	cout<<!obj1.x<<endl;
	cout<<!obj1.y;
}
int main()
{
overloading obj1(2,0);
!obj1;
//obj1.show_data();
return 0;
}
