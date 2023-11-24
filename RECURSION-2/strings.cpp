#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abc";
    cout<<s<<endl;
    // string input:
    //cin>>s;
    //cout<<s<<endl;
    // for spaced string input:
    //getline(cin,s);
    //cout<<s<<endl;
    // dynamic declaration of a string:
    // syntax: string* <varName> = new string;
    string* sp = new string;
    // assignment of dynamic string
    // syntax: *<varName> = "<value>";
    *sp = "def";
    cout<<sp<<endl;
    cout<<*sp<<endl;

    string s3 = s+ (*sp);
    cout<<s3<<endl;

    // size function on strings
    cout<<s3.size()<<endl;

    // substring function:
    // doesnt alter the original string
    // variant-1: .substr(startIndex);
    cout<<s3.substr(3)<<endl;
    // variant-2: .substr(startIndex,endIndex);
    cout<<s3.substr(1,4)<<endl;

    // .find()
    cout<<s3.find("g")<<endl;

    

}

/*
    1. Strings are mutable
    2. they behave like array of characters => hence each character is accessible by it's index
    3. concatenation is possible
    4. useful functions like string, substring and find() can be used
*/