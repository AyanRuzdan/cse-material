#include <iostream>
#include <string>
using namespace std;

template <class T>  //Template with varibale datatype T
class vector{
    public:
        T *arr; 
        int size;
        vector(int size){
            this->size = size;
            arr = new T[size];
            cout<<"Array formed"<<endl;
        }

        void display(){
            for (int i = 0; i <= size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void mysize(int);

};


int main(){
    vector <int> obj_int(3);  //int object
    obj_int.arr[0] = 0;
    obj_int.arr[1] = 1;
    obj_int.arr[2] = 2;
    obj_int.arr[3] = 3;

    obj_int.display();

    vector <float> obj_float(3);  //float object
    obj_float.arr[0] = 0.0;
    obj_float.arr[1] = 1.1;
    obj_float.arr[2] = 2.2;
    obj_float.arr[3] = 3.3;

    obj_float.display();

return 0;
}