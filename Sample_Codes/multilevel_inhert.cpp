#include <iostream>
using namespace std;

class Student
{ // Base class
protected:
    int roll;

public:
    void setRoll(int);
    void getRoll();
};

void Student ::setRoll(int num)
{
    roll = num;
}

void Student ::getRoll()
{
    cout << "The Roll No is : " << roll << endl;
}

class Exam : public Student
{ // inherted class{from parent class}
protected:
    float math, physics;

public:
    void setMarks(float, float);
    void getMarks();
};

void Exam ::setMarks(float m1, float m2)
{
    math = m1;
    physics = m2;
}

void Exam ::getMarks()
{
    cout << "Maths : " << math << endl;
    cout << "Physics : " << physics << endl;
}

class Result : public Exam{
    float percent;
    public:
        void display();
};

void Result :: display(){
    cout<<"Roll : "<<roll<<endl;
    cout<<"Total score : "<<(math + physics)<<endl;
    cout<<"Percentage : "<<(math + physics)/2.0<<endl;
}

int main()
{
    Result me;
    me.setRoll(12);
    me.setMarks(91, 92);
    me.display();
    

    return 0;
}