/* Functions of stack:
data members: head
constructor: head is initialized to null
push: create a newNode and link accordingly 
      [insertion from front]
pop: return the data value of head
     and bring head to next node
top: return data value of head
size: mantain counter updation with push & pop function
isEmpty: check if head is null
all of this is calculated with order of 1
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

int main() {
    Stack<char> st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}