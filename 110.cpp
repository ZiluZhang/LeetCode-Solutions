/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(!isBalanced(root->left))
            return false;
        if(!isBalanced(root->right))
            return false;
        int d1 = depth(root->left);
        int d2 = depth(root->right);
        return abs(d1 - d2) <= 1;
        
    }
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};