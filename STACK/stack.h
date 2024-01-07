/* This is a header file
    It can be included in any file
    This file CAN'T contain a main function
    to include this file: #include "stack.h"; 
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int n;

    public:

    Stack(){
        n=0;
        head = NULL;
    }

    int getSize(){
        return n;
    }

    bool isEmpty(){
        return head==NULL;
    }

    void push(T ele){
        Node<T> *newNode = new Node<T>(ele);
        newNode->next = head;
        head = newNode;
        n++;
    }

    T pop(){
        if(head!=NULL){
            /* without condition if the head was null 
            we'll get segmentation fault*/
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            n--;
            return ans;
        }
        return -1;
    }

    T top(){
        if(head!=NULL){
            return head->data;
        }
        return -1;
    }

};