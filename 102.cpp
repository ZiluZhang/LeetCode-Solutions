// Binary Tree Level Order Traversal
// 用queue，myqueue.size()
// 记得判断root非空！

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        int num = 0;
        vector<vector<int>> res;
        while(!q.empty()) {
            num = q.size();
            vector<int> tmp;
            for(int i = 0; i < num; i++) {
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};