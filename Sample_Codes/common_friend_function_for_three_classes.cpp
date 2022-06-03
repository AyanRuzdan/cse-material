#include<iostream>
using namespace std;
class LG;//Forward declaration--It is done when class is used before its definition
class samsung;//Forward declaration
class onida
{
	int price;
	public:
		void getdata()
		{
			cout<<"\n Enter price for onida l.c.d:";
			cin>>price;
		}
		friend void check(LG,samsung,onida);
};
class LG
{
	int price;
	public:
		void getdata()
		{
			cout<<"\n Enter price for LG l.c.d:";
			cin>>price;
		}
		friend void check(LG,samsung,onida);
};
class samsung
{
	int price;
	public:
		void getdata()
		{
			cout<<"\n Enter price for samsung l.c.d:";
			cin>>price;
		}
		friend void check(LG,samsung,onida);
};

void check(LG s1,samsung s2,onida s3)
{
	if(s1.price>s2.price&&s1.price>s3.price)
	{
		cout<<"\n LG L.C.D is costlier with value:"<<s1.price;
	}
	else if(s2.price>s1.price&&s2.price>s3.price)
	{
	    cout<<"\n samsung L.C.D is costlier with value:"<<s2.price;
	}
	else
	{
		cout<<"\n onida L.C.D is costlier with value:"<<s3.price;
	}
}
int main()
{
	LG s1;
	samsung s2;
	onida s3;
	s1.getdata();
	s2.getdata();
	s3.getdata();
	check(s1,s2,s3);
	return 0;
}





