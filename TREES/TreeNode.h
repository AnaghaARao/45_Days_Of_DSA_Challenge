#include<vector>
using namepace std;

template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children; // taken so by default
        // actual declarartions: vector<TreeNode<T>*> children;
};


/* 
    possible methods of executions:
    linked list: has access issues
    array: has predefined size issues
    better soln: vector
*/