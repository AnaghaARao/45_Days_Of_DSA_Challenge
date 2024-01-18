#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no. of children of "<< front->data;
        int numChild;
        cin>>numChild;
        for(int i = 0 ; i < numChild ; i++){
            int childData;
            cout<<"Enter "<< i <<"th child of "<< front->data << endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData); // dynamic allocation to ensure that memory isnt lost
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


TreeNode<int>* takeInput() {
    int rootData;
    cout<< "Enter data\n";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<< "Enter no. of children of "<< rootData << endl;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL) return;
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        TreeNode<int>* front = pending.front();
        pending.pop(); 
        cout<< front->data<<":";
        for(int i = 0 ; i < front->children.size() ; i++){
            if(i==0) cout<< front->children.at(i)->data;
            else cout<<","<<front->children.at(i)->data;
            pending.push(front->children.at(i));
        }
        cout<<endl;
    }

}

void printTree(TreeNode<int>* root){
    if(root==NULL) return; // #Edge_Case
    cout<< root->data <<":";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<< root->children.at(i)->data << ",";
    }
    cout<< endl;
    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children.at(i));
    }
    // no need for a base case as the loop automatically works as one
}

int countNodes(TreeNode<int>* root){
    int cnt = 1;
    for(int i = 0 ; i < root->children.size() ; i++){
        cnt += countNodes(root->children.at(i));
    }
    return cnt;
}

int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    // ToDo delete the tree
}