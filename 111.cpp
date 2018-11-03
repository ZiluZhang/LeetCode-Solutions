// Minimum Depth of Binary Tree
// 注意！不能直接返回min+1，因为有的左/右空，说明不是叶子节点！
// 


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};


// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root == NULL)
//             return 0;
//         if(root->left == NULL)
//             return minDepth(root->right)+1;
//         if(root->right == NULL)
//             return minDepth(root->left)+1;
//         return min(minDepth(root->left), minDepth(root->right)) + 1;
//     }
// };