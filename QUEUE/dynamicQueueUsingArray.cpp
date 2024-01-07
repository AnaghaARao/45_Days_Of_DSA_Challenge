/*
    IMPLEMENTATION  OF CIRCULAR QUEUE USING ARRAYS: 
    Implementation factors:
    Data members:
    1. Array- to store values
    2. front(firstIndex) - ptr to the first element/ deletion element
    3. rear(nextIndex) - ptr to insertion index
    4. capacity - to store capacity of array
    5. n - size of the array at any instance

    Data functions:
    1. enqueue(T ele): to enter elements into the array...
                       in case capacity is full then the 
                       array is updated to have 2 times the 
                       original number of elements
    2. dequeue(): similar to pop=> removes the 1st element inserted
    3. front(): similar to top=> returns the 1st ele...doesnt delete it
    4. size(): returns the current size of the queue
    5. isEmpty(): returns boolean value indicating whether 
                  the queue is empty or not
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class DynamicQueueUsingArray{
    T *data;
    int front;
    int rear;
    int capacity;
    int n;

    public:
    DynamicQueueUsingArray(int s){
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

    /*void enqueue(T ele){
        if(n == capacity){
            // dynamically creating new array 
            T *newData = new T[capacity*2];
            int j = 0;
            // for function conditions are v. important
            for(int i = front;i != rear; i = (i + 1) % capacity) {
                newData[j] = data[i];
                j++;
            }
            // in the new queue we will arrange all elements in order from 0th index
            front = 0;
            // the new next element is the capacity. This is were the next element will be inserted
            rear=capacity;
            capacity*=2;
            delete [] data;
            data = newData;
        }
        data[rear] = ele;
        // Moving the ptr to the next position for insertion in the future
        rear = (rear+1)%capacity;
        if(front == -1) front = 0;
        n++;
        return;
    } */

    void enqueue(T ele) {
        if (n == capacity) {
            /* dynamically creating new array */
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = front; i != rear; i = (i + 1) % capacity) {
                newData[j] = data[i];
                j++;
            }
            /* Insert the new element at the rear in the new queue */
            newData[j] = ele;
            front = 0;
            rear = j + 1;
            capacity *= 2;
            delete[] data;
            data = newData;
        } else {
            data[rear] = ele;
            rear = (rear + 1) % capacity;
            if (front == -1) front = 0;
        }
        n++;
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
    DynamicQueueUsingArray<int> obj(5);
    cout<<obj.isEmpty()<<endl;
    cout<<obj.size()<<endl;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    obj.enqueue(60);
    cout<<obj.size()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.size()<<endl;
    cout<<obj.findFront()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.size()<<endl;

}