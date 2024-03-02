/*
    For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. 
    Elements on every level will be printed in a linear fashion and a single space will separate them.
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(nullptr);
    while(! q.empty()){
        BinaryTreeNode<int>* front = q.front();
        if(front != nullptr) {
            cout << front->data << "\t";
            q.pop();

            // adding left subtree
            if(front->left != NULL){
                q.push(front->left);
            }
            // adding right subtree
            if(front->right != NULL){
                q.push(front->right);
            }
        }
        else{
            // checking if there are elements after the current nullptr or not
            q.pop();
            if(q.empty()) break;
            else q.push(nullptr);
            cout<<endl;
        }
    }
}

/*
    Here we follow the principle of using nullptr as a indicator of moving to the next line
    and adding another nullptr to the end of queue to mark the finish of the newly added level.
*/