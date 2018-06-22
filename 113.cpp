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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> tmp;
        getpath(root, tmp, sum, res);
        return res;
    }
    
    void getpath(TreeNode* cur, vector<int> prev, int remain, vector<vector<int>>& res)
    {
        if(cur == NULL)
            return;
        remain -= cur->val;
        prev.push_back(cur->val);
        if(remain == 0 && cur->left == NULL && cur->right == NULL)
        {
            res.push_back(prev);
            return;
        }
        else if(cur->left != NULL || cur->right != NULL)
        {
            getpath(cur->left, prev, remain, res);
            getpath(cur->right, prev, remain, res);
        }
        return;
    }
};