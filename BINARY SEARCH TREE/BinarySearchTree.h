#include "BinaryTreeNode.h"
class BST<int>{
    private:
        BinaryTreeNode<int>* root;
        BST() {
            root = NULL;
        }
        ~BST() {
            delete root;
        }

        bool searchHelper(int data, BinaryTreeNode<int>* root){
            // helper function for search operation
            if(root == NULL){
                return false;
            }
            if(root->data == data) return true;

            if(rot->data > data){
                // call on left subtree
                return searchHelper(data, root->left);
            }
            else{
                // call on right subtree
                return searchHelper(data, root->right);
            }
            
        }

    public:
        bool search(int data){
            return searchHelper(data, root);
        }

        void deleteData(int data){

        }

        void insertData(int data){

        }


};