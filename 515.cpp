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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> tmp;
            TreeNode* cur = q.front();
            int max = cur->val;
            while(!q.empty())
            {
                cur = q.front();
                if(cur->val > max)
                    max = cur->val;
                q.pop();
                if(cur->left != NULL)
                    tmp.push(cur->left);
                if(cur->right != NULL)
                    tmp.push(cur->right);
                // tmp.push(cur);
            }
            res.push_back(max);
            while(!tmp.empty())
            {
                q.push(tmp.front());
                tmp.pop();
            }
        }
        return res;
    }
};