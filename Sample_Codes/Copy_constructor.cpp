#include<iostream>
using namespace std;
class example{
    int x,y;
    public:
    example(int a,int b){
        x=a;
        y=b;
    }
    example(example &obj){
    x=obj.x;
    y=obj.y;
    }
    void display(){
        cout<<"\n Values of x and y are:"<<x<<" "<<y;
    }
};
int main(){
    example obj1(2,5);
    obj1.display();
    example obj2(obj1);//Copy Constructor is called
    obj2.display();
    example obj3=obj1;//Second way of calling copy constructor
    obj3.display();
    return 0;
}