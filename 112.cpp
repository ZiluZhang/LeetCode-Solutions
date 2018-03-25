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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return hasPath(root, sum);
    }
    bool hasPath(TreeNode* begin, int subsum)
    {
        if(begin == NULL && subsum == 0)
            return true;
        if(begin == NULL)
            return false;
        if(begin->val == subsum && begin->left == NULL && begin->right == NULL)
            return true;
        return hasPathSum(begin->left, subsum - begin->val) || hasPathSum(begin->right, subsum - begin->val);
    }
};