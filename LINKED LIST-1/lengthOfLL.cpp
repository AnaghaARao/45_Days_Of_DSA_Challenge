#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};

int length(Node *head)
{
	Node *temp = head;
    int cnt = 0; // cause there is something in the head for sure
    while(temp->next!=NULL){ // ensures that -1 isnt included in the count for length of LL
        cnt+=1;
        temp = temp->next;
    }
    return cnt;
    // terminator in this case is -1....hence not to be included in length....taken care of by the while loop condition
}