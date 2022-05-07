#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Give sixe of array : ";
    cin>>size;
    cout<<endl;

    int elem; int arr[size];
    cout<<"Enter elements of array"<<endl;
    for (int i = 0; i<size; i++)
    {
        cin>>elem;
        arr[i] = elem;
    }

//binary search
    int num; int mid;
    cout<<"Enter number to search : ";
    cin>>num;
    cout<<endl;

    int low = 0;
    int high = size;

    while (true)
    {
        mid = int(low + high)/2;
        if (arr[mid] == num)
        {
            cout<<"Number is at "<<mid<<endl;
            break;
        }
        else if (low > high)
        {
            cout<<"Not found"<<endl;
            break;
        }
        else if ( arr[mid] > num)
        {
            high = mid-1;
        }
        else if ( arr[mid] < num)
        {
            low = mid + 1;
        }
    }  
}