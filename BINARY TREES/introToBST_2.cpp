#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNode.push(child);
        }

        cout<<"Enter right child of " << front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNode.push(child);

        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
    // base case:
    if(root == NULL) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){

        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<":";

        if(front->left != NULL){
            pendingNodes.push(front->left);
            cout<<"L:"<<front->left->data;
        }
        else{
            cout<<"L:-1";
        }

        cout<<",";

        if(front->right != NULL){
            pendingNodes.push(front->right);
            cout<<"R:"<<front->right->data;
        }
        else{
            cout<<"R:-1";
        }

        cout<<endl;
    }
}

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    int sum = 1;
    sum += countNodes(root->left);
    sum += countNodes(root->right);

    return sum;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << countNodes(root);
    delete root;
}
