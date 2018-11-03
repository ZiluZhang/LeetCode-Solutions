// Balanced Binary Tree
// 递归，对每一个节点，求左右子树的高度
// 可能的剪枝：如果当前节点已经左右高度已经不平衡了，高度返回-1，可以判断一下提前return false

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};


// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL)
//             return true;
//         if(!isBalanced(root->left))
//             return false;
//         if(!isBalanced(root->right))
//             return false;
//         int d1 = depth(root->left);
//         int d2 = depth(root->right);
//         return abs(d1 - d2) <= 1;
        
//     }
//     int depth(TreeNode* root) {
//         if(root == NULL)
//             return 0;
//         if(root->left == NULL && root->right == NULL)
//             return 1;
//         return max(depth(root->left), depth(root->right)) + 1;
//     }
// };