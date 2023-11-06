#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //vector definition:
    vector<int> v;

    // vector of size 5
    vector<int> v1(5);
    for(int i = 0 ; i < 5 ; i++) cout<<v1[i]<<" ";
    cout<<endl;

    // vector of size 10 initialized to 2
    vector<int> v2(10,2);
    for(int i = 0 ; i < 10 ; i++) cout<<v2[i]<<" ";
    cout<<endl;

    //taking vector input at runtime
    for(int i = 0 ; i < 5 ; i++) v1[i]=i;
    for(int i = 0 ; i < 5 ; i++) cout<<v1[i]<<" ";

    // to find size of vector:
    cout<<v.size()<<endl;

    // to add elements are the end of the vector
    v.push_back(6);
    cout<<v.size()<<endl;

    // to remove an element from the end of a vector
    v.pop_back();
    cout<<v.size()<<endl;

    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(11);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    cout<<v2.size()<<" "<<v2.capacity()<<endl;

}

/*
    Vector is a dynamic array
    by default vector elements are initialized to 0
    vector is dynamic as it doubles the original capacity everytime the capacity is used
    and more the initial capacity the vector is initialized
    vector can be traversed using for-loop
    vector input can be taken using cin / push_back function
*/