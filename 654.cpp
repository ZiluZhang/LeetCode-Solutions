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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return NULL;
        if(len == 1)
            return new TreeNode(nums[0]);
        int max = nums[0];
        int idx = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] > max)
            {
                max = nums[i];
                idx = i;
            }
        TreeNode* root = new TreeNode(max);
        vector<int> l(nums.begin(), nums.begin()+idx);
        vector<int> r(nums.begin()+idx+1, nums.end());
        // cout << max << " " << idx << endl;
        // if(idx != 0)
        //     copy(nums.begin(), nums.begin()+idx, l.begin());
        // if(idx != len-1)
        //     copy(nums.begin()+idx+1, nums.end(), r.begin());
        // cout << "asfgds" << endl;
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);
        return root;
    }
};