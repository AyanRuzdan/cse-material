#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class error
{
int err_code;
char *err_desc;
public:
error(int c, char *d)
{
err_code=c;
err_desc=new char[strlen(d)+1];
strcpy(err_desc, d);
}

void err_display()
{
cout<<"\nError code:"<<err_code<<"\nError desc:"<< err_desc;
}
};
int main()
{
try
{
cout<<"\nPress any key:";
getch();
error obj(99,"This is error");
throw obj;
}
catch(error e)
{
cout<<"\nException caught successfully";
e.err_display();
}
return 0;
}
