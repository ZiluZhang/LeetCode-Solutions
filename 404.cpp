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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);
        // if(root->left != NULL)
        //     return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        // if(root->left == NULL)
        //     return sumOfLeftLeaves(root->right);
        // // if(root->right == NULL)
        // //     return root->left->val + sumOfLeftLeaves(root->left);
        // cout << root->left->val << endl;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};