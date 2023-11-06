#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,char> a, pair<int,char> b){
    return (a.second < b.second);
}
int main(){
    // declaration
    //pair<int, char> p = {10,'A'};
    //pair<int,char> p;
    //pair<int,char> p(10,'A');
    pair<int,char> p = make_pair(10,'A');

    //accessing values:
    cout << p.first << " " << p.second<< endl;

    // creating a list of pairs using vectors
    vector<pair<int,char>> students;
    int n , rollNum;
    char section;

    cin>>n;
    for(int i = 0 ; i < n ; i++ ){
        cin>>rollNum>>section;
        students.push_back({rollNum,section});
    }

    // sorting a list of pair - default behaviour is ascending order
    sort( students.begin(),students.end());

    for(int i = 0 ; i < n ; i++ ){
        cout << students[i].first << " " << students[i].second << endl;
    }

    // comparision of pairs
    cout << (students[0] < students[1]) << endl;

    // to sort based on only the 2nd value we shd compose our own function
    sort(students.begin(),students.end(),comp);

    for(int i = 0 ; i < n ; i++ ){
            cout << students[i].first << " " << students[i].second << endl;
    }

}

/*
    Declaration:
    pair< datatype1 , datatype2> varName;

    Accessing the values:
    .first and .second

    Creating a list of pairs:
    using arrays and vectors

    Note: {} represents a pair

    How comparision happens with pairs:
    the .first elements of all is compared
    the tie breaker/second option for comparision is .second elements
    ie, .second elements are 
    => second values are generally tie-breakers
*/