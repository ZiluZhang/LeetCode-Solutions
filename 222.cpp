// Count Complete Tree Nodes
// complete tree就是非常规矩，从上到下从左到右排
// 看最左最右路径高度，如果一样，说明满，可以用位运算
// 如果不一样，递归，算左子树和右子树，加起来再加自己

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* tmp = root;
        int l = 0;
        int r = 0;
        while(tmp->left) {
            l++;
            tmp = tmp->left;
        }
        tmp = root;
        while(tmp->right) {
            r++;
            tmp = tmp->right;
        }
        if(r == l)
            return (1<<(r+1))-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};