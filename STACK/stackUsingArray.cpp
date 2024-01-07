#include<bits/stdc++.h>
using namespace std;

class StackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex=0;
        capacity = totalSize;
    }

    // function to return the number of elements present in my stack
    int size(){
        return nextIndex;
    }

    // function to check if the stack is empty
    bool isEmpty(){
        return nextIndex==0;
        /*
            return true if nextIndex = 0 else returns false
        */
    }

    //Function to insert element into the stack
    void push(int ele){
        if(nextIndex == capacity){
            cout<< "Stack full"<<endl;
            return;
        }
        data[nextIndex++]=ele;
    }

    //function to delete an element
    int pop(){
        if(isEmpty()) {
            cout<<"Stack empty"<<endl;
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    //function to return the top element
    int top(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};

int main() {
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    cout<< s.top() <<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;

}