#include<iostream>
using namespace std;
class example
{
	int n;
	public:
		int getdata()
		{
			cout<<"\n Enter the number of terms:";
			cin>>n;
			return n;
		}
		int fibo(int x)
		{
			if(x==0)
			return 0;
			else if(x==1)
			return 1;
			else
			return (fibo(x-1)+fibo(x-2));
		}
};
int main()
{
	example obj1;
	int terms;
	int c=0;
	terms=obj1.getdata();
	for(int i=1;i<=terms;i++)
	{
		cout<<"\n Fibonacci term is:"<<obj1.fibo(c);
		c++;
	}
	return 0;
}
