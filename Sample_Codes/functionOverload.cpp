#include <iostream>
using namespace std;
 
class overloading{
    int x;
    public:
        overloading();
        overloading(int a){
            x = a;
        }

        void showdata(){
            cout<<x<<endl;
        }

        friend overloading operator+ (overloading, overloading);
        friend overloading operator* (overloading, overloading);
        friend overloading operator/ (overloading, overloading);
        friend overloading operator% (overloading, overloading);
        friend bool operator>= (const overloading, const overloading);
};

overloading operator + (overloading o1, overloading o2 ){
    overloading obj;
    obj.x = o1.x + o2.x;
    return obj;
}
 
overloading operator * (overloading o1, overloading o2 ){
    overloading obj;
    obj.x = (o1.x * o2.x);
    return obj;
}

overloading operator % (overloading o1, overloading o2 ){
    overloading obj;
    obj.x = o1.x % o2.x;
    return obj;
}

overloading operator / (overloading o1, overloading o2 ){
    overloading obj;
    obj.x = (o1.x / o2.x);
    return obj;
}

bool operator >= (overloading o1, overloading o2){
    if (o1.x >= o2.x) return true;
    else return false;
}

int main(){
    int n1, n2, n3, n4, n5, n6;
    cout<<"Give Value For Objects"<<endl;
    cin>>n1>> n2>> n3>> n4>> n5>> n6;
    overloading o1(n1), o2(n2), o3(n3), o4(n4), o5(n5), o6(n6);
    overloading o7 = ((o1+o2)%(o3*o4) >= (o5/o6));
    o7.showdata();
return 0;
}