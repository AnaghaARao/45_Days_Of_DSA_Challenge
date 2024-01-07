/*
    IMPLEMENTATION  OF CIRCULAR QUEUE USING ARRAYS: 
    Implementation factors:
    Data members:
    1. Array- to store values
    2. front - ptr to the first element/ deletion element
    3. rear - ptr to insertion index
    4. capacity - to store capacity of array
    5. n - size of the array at any instance

    Data functions:
    1. enqueue(T ele): to enter elements into the array
    2. dequeue(): similar to pop=> removes the 1st element inserted
    3. front(): similar to top=> returns the 1st ele...doesnt delete it
    4. size(): returns the current size of the queue
    5. isEmpty(): returns boolean value indicating whether 
                  the queue is empty or not
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int front;
    int rear;
    int capacity;
    int n;

    public:
    QueueUsingArray(int s){
        data = new T[s];
        front = -1;
        rear = 0;
        capacity=s;
        n = 0;
    }

    bool isEmpty(){
        return n==0;
    }

    int size(){
        return n; 
    }

    void enqueue(T ele){
        if(n == capacity){
            cout<<"Queue full"<<endl;
            return;
        }
        if(front == -1) front = 0;
        data[rear] = ele;
        rear = (rear+1)%capacity;
        n++;
        return;
    }

    T dequeue(){
        if(!isEmpty()){
            T ans = data[front];
            front = (front+1)%capacity;
            n--;
            return ans;
        }
        cout<<"Queue empty"<<endl;
        return 0;
    }

    T findFront(){
        if(!isEmpty()){
            return data[front];
        }
        cout<<"Queue is empty"<<endl;
        return 0;
    }
};

int main(){
    QueueUsingArray<int> obj(5);
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    obj.enqueue(60);
    cout<<obj.dequeue()<<endl;
    cout<<obj.findFront()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.size()+1<<endl;

}