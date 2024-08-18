#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> ourMap; 

    // insertion:
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // find or access
    cout<< ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;

    cout<<ourMap.at("ghi")<<endl; // throws an exception as the key doesnt exist
    cout<< ourMap["ghi"]<<endl; // inserts the key of it doesnt exist

    // check presence
    if(ourMap.count("ghi") > 0){ // one value exists only once in a map -> so can use anything
        cout<<"ghi is present"<<endl;
    }

    // erase
    ourMap.erase("ghi");
    if(ourMap.count("ghi") > 0){ // this isnt printing
        cout<<"ghi is present"<<endl;
    }
}