// Lowest Common Ancestor of a Binary Search Tree
// 利用好二叉搜索树！

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != p && root != q)
        {
            int rvalue = root->val;
            int pvalue = p->val;
            int qvalue = q->val;
            if(rvalue >= pvalue && rvalue >= qvalue)
                root = root->left;
            else if(rvalue <= pvalue && rvalue <= qvalue)
                root = root->right;
            else
                break;
        }
        return root;
    }
};