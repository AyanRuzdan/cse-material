#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
fstream s;
int lines=1,nospaces=0,nochars=0;
s.open("Lines.txt",ios::in);
char ch;
if(!s)
{
    cout<<"\n File could not be opened";
    exit(1);
}
ch=s.get();
while(s.eof()==0)
{
    nochars++;
    if(ch=='\n')
    {
        lines++;
    }
    else if(ch==' ')
    {
        nospaces++;
    }
        ch=s.get();
}
cout<<"\n Lines:"<<lines<<" "<<"Spaces:";
cout<<nospaces<<" "<<"Chars:"<<nochars;
return 0;
}
