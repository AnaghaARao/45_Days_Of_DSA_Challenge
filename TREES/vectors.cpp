#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector is a template
    vector<int> v;  // static allocation
    //vector<int> *vp = new vector<int>(); // dynamic allocation

    // function to enter elements into the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;

    v[3] = 1002;
    v[4] = 1234;

    v.push_back(23);
    v.push_back(45);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    // cout<<v[5]<<endl;
    // cout<<v[6]<<endl;

    // [] can be used to access the elements of the vector
    // why we use push_back instead of simply allocating using []?
    // this is cause push_back checks for current size, capacity and 
    // need to allocate more memory which cant be done by simply using [] alone
    // if we intialize vectors using [] we would be accessign memeory that isnt allocated to us - WRONG PRACTICE

    // functions of vector
    // 1. .push_back()
    // 2. .pop_back()
    // 3. .size()
    // 4. .at(<index>)
    // 5. .capacity()

    cout<<endl;
    cout<< v.capacity();
    cout<< v.size()<<endl;
    v.pop_back();
    cout<< v.size()<<endl;
    cout<< v.at(3)<<endl;
    cout<< v.capacity();



}