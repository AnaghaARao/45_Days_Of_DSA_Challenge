/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, int &sum){ // use pass by reference to update value of sum
        if(root->right){
            root->right = helper(root->right, sum);
        }

        root->val = root->val + sum;
        sum = root->val;

        if(root->left){
            root->left = helper(root->left, sum);
        }


        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        int sum = 0;
        TreeNode* newRoot = helper(root, sum); // send sum as variable to enable pass by reference
        return newRoot;
    }
};