// Valid Binary Search Tree
// 写一个函数，看子树是不是满足(min, max)范围
// 注意整数边界，可以用Long来避免越界
// INT_MIN这种本身还是个int

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits.h>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return help(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
    
    bool help(TreeNode* cur, long left, long right) {
        if(cur == NULL) return true;
        long cur_val = cur->val;
        return left < cur_val
            && cur_val < right 
            && help(cur->left, left, cur_val) 
            && help(cur->right, cur_val, right);
    }
};