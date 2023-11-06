#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> num(5);

    for(int i = 0 ; i < 5 ; i++) cin>>num[i];

    //traversal method - 1: UISNG for LOOP
    for(int i = 0 ; i < 5 ; i++) cout<<num[i]<<" ";
    cout<<endl;

    // traversal method - 2: USING iterators
    // defining iterators:
    vector<int> :: iterator i = num.begin();
    for(; i != num.end(); i++){
        cout<< *i <<" ";
    }
    cout<<endl;

    // accessing elements of a vector - USING .at() - RECOMMENDED METHOD
    for(int i = 0 ; i < 5 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;
    // this function doesnt allow us to print out-of-range indices

    // to reverse the content of a vector
    // for range (l,r+1) = reverse(base+l,base+r)
    reverse(num.begin(),num.end());
    for(int i = 0 ; i < 5 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;

    // to find the front element of the container - .front()
    // to find the last/back element of container - .back()
    cout<<num.front()<<" "<<num.back()<<endl;

    // to erase / delete a particular element - erase(index)
    num.erase(num.begin()+2);
    for(int i = 0 ; i < 4 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;

    // to erase / delete a range of elements - .erase(l,r)
    num.erase(num.begin() , num.begin() + 2);
    for(int i = 0 ; i < 2 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;

    num.push_back(2199);
    num.push_back(32);
    num.push_back(222);
    for(int i = 0 ; i < 2 ; i++) cout<<num.at(i)<<" ";


    // sorting a vector - sort(l,r)
    sort(num.begin(),num.end());
    for(int i = 0 ; i < 2 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;

    // sorting in DESENDING ORDER : **very important**
    sort(num.begin(),num.end(),greater<int>());
    // here greater is a predefined function
    // however this function can be replaced by user-defined function as well
    for(int i = 0 ; i < 2 ; i++) cout<<num.at(i)<<" ";
    cout<<endl;

    // to check if the container is empty - .empty();
    cout<< num.empty()<<endl;

    // function to empty a function - .clear(); 
    num.clear();
    cout<<num.empty()<<endl;


}