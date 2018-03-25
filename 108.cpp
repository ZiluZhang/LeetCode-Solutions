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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return NULL;
        if(len == 1)
            return new TreeNode(nums[0]);
        int mid = len/2;
        // cout << mid << endl;
        // cout << nums[mid] << endl;
        TreeNode* tmp = new TreeNode(nums[mid]);
        vector<int> l;
        l.assign(nums.begin(), nums.begin()+mid);
        vector<int> r;
        r.assign(nums.begin()+mid+1, nums.end());
        tmp->left = sortedArrayToBST(l);
        tmp->right = sortedArrayToBST(r);
        return tmp;
    }
};