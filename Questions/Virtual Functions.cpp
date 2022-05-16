//Problem Statement: https://www.hackerrank.com/challenges/virtual-functions/problem?h_r=next-challenge&h_v=zen&isFullScreen=true
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Main Code
class Person{
    protected:
        string name;
        int age;
    public:
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor: public Person{
    int publications;
    int id;
    static int cur_id;
    public:
    Professor(){ cur_id++; id = cur_id;}
        void getdata();
        void putdata();
};

int Professor:: cur_id = 0;

void Professor :: getdata(){
    cin>>name>>age>>publications;
}

void Professor:: putdata(){
    cout<<name<<' '<<age<<' '<<publications<<' '<<id<<endl;
}

class Student: public Person{
    int marks[6];
    int id;
    static int cur_id;
    public:
    Student(){cur_id++; id = cur_id;}
        void getdata();
        void putdata();
};

void Student:: getdata(){
    cin>>name>>age;
    for(int i = 0; i < 6; i++){
        cin>>marks[i];
    }
}

void Student:: putdata(){
    cout<<name<<' '<<age<<' ';
    int sum = 0;
    for(int i = 0; i < 6; i++){
        sum+=marks[i];
    }
    cout<<sum<<' '<<id<<endl;
}

int Student :: cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
