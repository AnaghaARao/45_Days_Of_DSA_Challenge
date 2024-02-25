/*
    Binary tree is a type of tree where every node has a maximum of 2 children
    The binary tree node class needs 3 data members: data, left_node, right_node
*/

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data){
            this->data = data;
            right = NULL;
            left = NULL;
        }

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};