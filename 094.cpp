// Binary Tree Inorder Traversal
// 对比144中序，145后序
// inorder中序
// 用栈，while循环是栈非空或当前指针非空
// 当前指针非空，说明没到最左，继续推栈
// 否则访问栈顶指针的值，当前指针为栈顶右指针，pop

// mystack.pop()不返回值

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL) return res;
        TreeNode* tmp = root;
        while(!s.empty() || tmp != NULL) {
            if(tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            }
            else {
                tmp = s.top();
                s.pop();
                res.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        return res;
    }
};

// 递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode* cur, vector<int> & res) {
        if(cur == NULL) return;
        inorder(cur->left, res);
        res.push_back(cur->val);
        inorder(cur->right, res);
        return;
    }
};