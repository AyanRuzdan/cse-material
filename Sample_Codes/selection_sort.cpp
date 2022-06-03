#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cout<<"Size of array : ";
    cin>>num;
    cout<<endl;

    int arr[num]; int elem;
    cout<<"Enter elements for array"<<endl;
    for (int i = 0; i<num; i++){
        cin>>elem;
        arr[i] = elem;
    }

// selection sort
    for (int i = 0; i < num; i++){
        for (int j = i; j < num; j++){
            if (arr[i] > arr[j]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
   for (int i = 0; i < num; i++){
       cout<<arr[i]<<" ";
   }
}