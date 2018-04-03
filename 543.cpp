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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        depth(root);
        return res - 1;
    }
    
    int depth(TreeNode* node) {
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right == NULL)
            return 1;
        int l = depth(node->left);
        int r = depth(node->right);
        res = max(res, l+r+1);
        return max(l, r) + 1;
    }
};