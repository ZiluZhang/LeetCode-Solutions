// Flatten Binary Tree to Linked List
// 注意看题，是每个节点都把left插到right
// 


// 递归
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = tmp;
        return;
    }
};

// 迭代
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur) {
            if(cur->left) {
                TreeNode* tmp = cur->left;
                while(tmp->right) tmp = tmp->right; // get last right leaf
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
        return;
    }
};