#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int arr[5];

    // to initialize all elements of array to 0/-1
    memset(arr , -1 , sizeof(arr));
    for(int i = 0 ; i < 5 ; i++) cout<<arr[i]<<" ";
    // diadvantage: works only for -1 and 0
    cout<<endl;

    // to initialize all elements of array with any value
    fill(arr, arr+5, 10);
    for(int i = 0 ; i < 5 ; i++) cout<<arr[i]<<" ";
    cout<<endl;

    int arr1[5]={3,2,5,4,1};

    // to sort the array
    sort(arr1 , arr1 + 5 );
    for(int i = 0 ; i < 5 ; i++) cout<<arr1[i]<<" ";
    cout<<endl;

    // to reverse an array
    reverse(arr1, arr1+5);
    for(int i = 0 ; i < 5 ; i++) cout<<arr1[i]<<" ";
    cout<<endl;

    //to swap elements of an array
    swap(arr1[2],arr1[0]);
    for(int i = 0 ; i < 5 ; i++) cout<<arr1[i]<<" ";
    cout<<endl;

    // to find size of an array
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Size = "<<n<<endl;

    // here all range based functions can have diff range
    // if range is l-r then l => included ; r => excluded

}