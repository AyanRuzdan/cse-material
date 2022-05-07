#include <iostream>
using namespace std;

class Triangle{
    int base;
    float height;
    public:
        Triangle(int b, float h){
            base = b;
            height = h;
        }

        operator float(){
            return float(base)*height*0.5;
        }
};
 
int main(){
    int base; float height;
    cin>>base>>height;
    Triangle triangle(base, height);
    float area = (float)triangle;
    cout<<area<<endl;
 
return 0;
}