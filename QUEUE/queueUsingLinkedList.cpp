/* IMPLEMENTAION OF QUEUE USING LINKEDLIST:
    Class members:
    1. head node: to delete the 1st element => front
    2. size: tracks the size of queue
    3. tail node: to insert the elements => rear

    Class functions:
    1. enqueue(T ele): create a new node and insert
    2. dequeue(): removes the 1st element
    3. front(): returns the front ndal value
    4. isEmpty(): checks if queue is empty
    5. size(): return the size of the queue
*/

#include<bits/stdc++.h>
using namespace std;

   template <typename T>
   class Node{
    public:
    Node<T> *next;
    T data;
    Node(T data){
        this->data = data;
        next = NULL;
    }

   };

   template <typename T>
   class QueueUsingLinkedList{
    Node<T> *head , *tail;
    int n;

    public:

    QueueUsingLinkedList(){
        n=0;
        head = NULL;
        tail = NULL;
    }

    int getSize(){
        return n;
    }

    bool isEmpty(){
        return n==0;
    }

    T front(){
        if(n==0) return 0;
        return head->data;
    }

    void enqueue(T ele){
        Node<T> *newNode = new Node<T>(ele);
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }

    T dequeue(){
        if(n==0) return 0 ;
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        n--;
        return ans;
    }

};

int main(){
    QueueUsingLinkedList<int> obj;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.getSize()<<endl;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    obj.enqueue(60);
    cout<<obj.getSize()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.getSize()<<endl;
    cout<<obj.front()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.getSize()<<endl;

}