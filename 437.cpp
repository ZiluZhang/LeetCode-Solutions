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
    int cnt = 0;
    int pathSum(TreeNode* root, int sum) {
        // cnt = 0;
        if(root == NULL)
            return cnt;
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
    
    void dfs(TreeNode* cur, int sum)
    {
        if(cur == NULL)
            return;
        int remain = sum - cur->val;
        if(remain == 0)
            cnt++;
        dfs(cur->left, remain);
        dfs(cur->right, remain);
        return;
    }
};