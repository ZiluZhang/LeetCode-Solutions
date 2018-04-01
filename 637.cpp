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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> tmp;
        // TreeNode* cur;
        tmp.push(root);
        while(!tmp.empty())
        {
            int len = tmp.size();
            long int sum = 0;
            for(int i = 0; i < len; i++)
            {
                TreeNode* cur = tmp.front();
                sum += cur->val;
                tmp.pop();
                if(cur->left != NULL)
                    tmp.push(cur->left);
                if(cur->right != NULL)
                    tmp.push(cur->right);
            }
            res.push_back((double)sum / len);
        }
        return res;
    }
};