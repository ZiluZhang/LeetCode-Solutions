// Sum Root to Leaf Numbers
// 根节点到叶节点是一条路径，求所有路径的和
// 
// 

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        getNum(root, 0, res);
        return res;
    }
    
    void getNum(TreeNode* root, int cur, int& res) {
        cur = cur*10 + root->val;
        if(!root->left && !root->right) {
            res += cur;
            return;
        }
        if(root->left) getNum(root->left, cur, res);
        if(root->right) getNum(root->right, cur, res);
        return;
    }
};