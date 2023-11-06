#include<bits/stdc++.h>
using namespace std;

auto sum(auto a , auto b){
    // return type as auto keyword is also a use case
    // but parameter type as auto usually leads to a warning
    return a+b;
}
int main(){
    auto s = "hello";

    vector<char> ar(5,'$');      
    for(auto ele : ar) cout<<ele<<"_";
    cout<<endl;

    vector<char> :: iterator j = ar.begin();
    auto i = ar.begin(); // auto keyword makes it easy to code

    cout<<sum("h",'5'); // doesnt give expected output
    // but works better with numbers

    // to make detection of real-numbers we need to add suffix
    auto num = 1.1f ; // make num a float type
    // without suffix num is considered double
    
}

/* 
what auto keyword does??
It helps initialize the variable without specifying the data type
It automatically detects the type of data being stored in the variable
It is most useful when associated with iterators...
we dont have to specify the type of iterator and give it such a big declaration
auto keyword makes the code clean, short and readable to a certain extent
*/
