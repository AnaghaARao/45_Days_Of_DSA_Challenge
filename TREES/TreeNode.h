#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children; // taken so by default
        // actual declarartions: vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }

        // destructor to delete the nodes of the tree
        ~TreeNode(){
            for(int i = 0 ; i < children.size() ; i++){
                delete children[i];
            }
        }
};


/* 
    possible methods of executions:
    linked list: has access issues
    array: has predefined size issues
    better soln: vector
*/