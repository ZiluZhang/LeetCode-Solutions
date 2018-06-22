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
    int longestUnivaluePath(TreeNode* root) {
        int max_num = 0;
        if(root == NULL)
            return max_num;
        dfs(root, max_num);
        return max_num;
    }
    
    int dfs(TreeNode* cur, int& m)
    {
        int l = 0;
        int r = 0;
        if(cur->left != NULL)
        {
            l = dfs(cur->left, m);
            if(cur->left->val == cur->val)
                l += 1;
            else
                l = 0;
        }
        if(cur->right != NULL)
        {
            r = dfs(cur->right, m);
            if(cur->right->val == cur->val)
                r += 1;
            else
                r = 0;
        }
        m = max(l+r, m);
        return max(l,r);
    }
};