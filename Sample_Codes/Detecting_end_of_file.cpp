#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
ofstream outFile;
outFile.open("Questions.txt");
outFile<<"\n What is C language?";
outFile<<"\n What is C++ language?";
outFile.close();
outFile.open("Answers.txt");
outFile<<"\n Structured language";
outFile<<"\n Object Oriented language";
outFile.close();
char quest[80],ans[80];
ifstream inpFile;
inpFile.open("Questions.txt");
cout<<"\n********Sample Questions for Quiz Contest********";
while(inpFile.eof()==0)//First way-Using eof()[Returns 0 until unless end of file is not reached]
{
inpFile.getline(quest,80);
cout<<"\n"<<quest;
}
inpFile.close();
inpFile.open("Answers.txt");
cout<<"\n\n*******Answers for Sample Question********";
while(inpFile)//Second way-Using object name
{
inpFile.getline(ans,80);
cout<<"\n"<<ans;
}
inpFile.close();
}
