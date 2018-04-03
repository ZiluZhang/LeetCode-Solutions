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
    set<int> nums;
    void findNums(TreeNode* node) {
        if(node == NULL)
            return;
        if(nums.find(node->val) == nums.end())
            nums.insert(node->val);
        findNums(node->left);
        findNums(node->right);
        return;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        findNums(root);
        if(nums.size() < 2)
            return -1;
        set<int>::iterator iter = nums.begin();
        iter++;
        // for(it = nums.begin(); it != nums.end(); it++)
        //     cout << *it << endl;
        return *(iter);
    }
};