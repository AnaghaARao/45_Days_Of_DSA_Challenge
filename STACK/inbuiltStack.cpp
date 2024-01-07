/* Functions of in-built stack:
object declaration: stack<datatype> objName;
push()
pop()
size()
empty()
top()
*/


#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    cout<< s.top() <<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
}