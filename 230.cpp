// Kth Smallest Element in a BST


// 递归，数左右子树个数
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int left = countNode(root->left);
        if(k <= left) return kthSmallest(root->left, k);
        else if(k > left + 1) return kthSmallest(root->right, k-left-1);
        else return root->val;
    }
    
    int countNode(TreeNode* root) {
        if(!root) return 0;
        return countNode(root->left) + countNode(root->right) + 1;
    }
};