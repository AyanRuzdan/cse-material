//Arrays
#include<iostream>
using namespace std;
int main()
{
	int n,i;
	int arr[]={1,2,3};//Size of this array is 3
	int arr1[2]={1,2};
	int arr2[5]={0};//All elements will be initialized to zero
	int arr3[5]={1};//Only first element will be initialized to 1 and rest will be zeros
	int arr4[100];
	int arr5[5]={};
	cout<<arr[0]<<endl;
	cout<<arr1[1]<<endl;
	cout<<arr[3]<<endl;
	cout<<"Memory taken is:"<<sizeof(arr1);
	cout<<"Address is:"<<&arr[0]+1<<" "<<arr+1<<" "<<&arr+1<<endl;
	//*************************************
	//Taking input from user
	cout<<"\n Enter size of array(Less than or equal to 100):";
	cin>>n;
	cout<<"\n Enter array elements:";
	for(i=0;i<n;i++)
	{
		cin>>arr4[i];
	}
	cout<<"\n Array elements are:";
	for(i=0;i<n;i++)
    {
		cout<<arr4[i]<<"\n";
	}
}
