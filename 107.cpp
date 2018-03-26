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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            queue<TreeNode*> tmp;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                if(n->left != NULL)
                    tmp.push(n->left);
                if(n->right != NULL)
                    tmp.push(n->right);
                q.pop();
                level.push_back(n->val);
            }
            while(!tmp.empty())
            {
                q.push(tmp.front());
                tmp.pop();
            }
            res.insert(res.begin(), level);
        }
        return res;
    }
};