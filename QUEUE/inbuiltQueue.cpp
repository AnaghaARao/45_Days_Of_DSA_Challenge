#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> obj;
    cout<<obj.empty()<<endl;
    cout<<obj.size()<<endl;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.push(60);
    cout<<obj.size()<<endl;
    obj.pop();
    obj.pop();
    obj.pop();
    cout<<obj.empty()<<endl;
    cout<<obj.size()<<endl;
    cout<<obj.front()<<endl;
    cout<<obj.empty()<<endl;
    cout<<obj.size()<<endl;


}