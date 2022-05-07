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

    int temp;
//Bubble sort
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j< size; j++)
        {
            if (arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] =  arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}