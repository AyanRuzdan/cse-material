#include<iostream>
using namespace std;
class sample
{
	int a;
	int b;
	public:
        friend float mean(sample);
		void setvalue()
		{
			a=45;
			b=40;
		}
};
float mean(sample s)
{
	return float(s.a+s.b)/2.0;
}
int main()
{
	sample X;
	X.setvalue();
	cout<<"Mean value for object X="<<mean(X)<<"\n";
	return 0;

}
