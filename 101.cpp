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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->right == NULL && root->left == NULL))
            return true;
        if(root->right == NULL || root->left == NULL || root->right->val != root->left->val)
            return false;
        return rightleft(root->right, root->left);
    }
    bool rightleft(TreeNode* r, TreeNode* l)
    {
        if(r == NULL && l == NULL)
            return true;
        if(r == NULL || l == NULL || r->val != l->val)
            return false;
        return rightleft(r->left, l->right) && rightleft(r->right, l->left);
    }
};