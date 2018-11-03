// Binary Tree Zigzag Level Order Traversal
// 用两个栈，两行两行的做
// 第一个栈出来的，先左后右到第二个
// 第二个栈出来的，先右后左到第一个

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> s1, s2;
        s1.push(root);
        vector<int> cur;
        vector<vector<int>> res;
        while(!s1.empty() || !s2.empty()) {
            cur.clear();
            while(!s1.empty()) {
                TreeNode* tmp = s1.top();
                s1.pop();
                cur.push_back(tmp->val);
                if(tmp->left) s2.push(tmp->left);
                if(tmp->right) s2.push(tmp->right);
            }
            if(cur.size())
                res.push_back(cur);
            cur.clear();
            while(!s2.empty()) {
                TreeNode* tmp = s2.top();
                s2.pop();
                cur.push_back(tmp->val);
                if(tmp->right) s1.push(tmp->right);
                if(tmp->left) s1.push(tmp->left);
            }
            if(cur.size())
                res.push_back(cur);
        }
        return res;
    }
};