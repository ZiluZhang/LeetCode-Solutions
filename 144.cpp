// Binary Tree Preorder Traversal
// 对比094中序，145后序
// 记得推栈先右后左
// 递归就不写了

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        s.push(root);
        while(!s.empty()) {
            tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if(tmp->right != NULL) s.push(tmp->right);
            if(tmp->left != NULL) s.push(tmp->left);
        }
        return res;
    }
};