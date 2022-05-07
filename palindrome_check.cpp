#include <iostream>

using namespace std;

int main(){
    int size;
    cout<<"Give sixe of array : ";
    cin>>size;
    cout<<endl;

    char arr[size+1];
    cout<<"Enter characters of array"<<endl;
    cin>>arr;

    bool palin = true;

//Check Palindrome
    for (int i = 0; i<size; i++)
    {
        if (arr[i] != arr[size-1-i])
        {
            palin = false;
            break;
        }
    }

    if (palin == true)
    {
        cout<<"Is palindrome"<<endl;
    }
    else
    {
        cout<<"Is not a palindrome";
    }
}