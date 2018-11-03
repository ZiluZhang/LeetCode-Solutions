// Path Sum
// 注意要判断叶子节点！！！！！
// 
// 

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPath(root, sum);
    }
    
    bool hasPath(TreeNode* head, int sum) {
        if(!head) return sum==0;
        if(!head->left && !head->right) return sum == head->val;
        if(!head->left) return hasPath(head->right, sum - head->val);
        if(!head->right) return hasPath(head->left, sum - head->val);
        return hasPath(head->left, sum - head->val) || hasPath(head->right, sum - head->val);
    }
};


// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         if(root == NULL)
//             return false;
//         return hasPath(root, sum);
//     }
//     bool hasPath(TreeNode* begin, int subsum)
//     {
//         if(begin == NULL && subsum == 0)
//             return true;
//         if(begin == NULL)
//             return false;
//         if(begin->val == subsum && begin->left == NULL && begin->right == NULL)
//             return true;
//         return hasPathSum(begin->left, subsum - begin->val) || hasPathSum(begin->right, subsum - begin->val);
//     }
// };