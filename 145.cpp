// Binary Tree Postorder Traversal
// 对比094前序，144中序
// 记得推栈先右后左

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        stack<pair<TreeNode*, bool>> s;
        s.push(pair<TreeNode*, bool>(root, false));
        TreeNode* tmp;
        while(!s.empty()) {
            tmp = s.top().first;
            if(s.top().second) {
                res.push_back(tmp->val);
                s.pop();
            }
            else {
                s.top().second = true;
                if(tmp->right != NULL) s.push(pair<TreeNode*, bool>(tmp->right, false));
                if(tmp->left != NULL) s.push(pair<TreeNode*, bool>(tmp->left, false));
            }
        }
        return res;
    }
};