// Convert Sorted Array to Binary Search Tree
// 递归，当前区间[i,j]
// 中间位置是parent，左边是left右边是right

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return NULL;
        return getPart(nums, 0, len-1);
    }
    
    TreeNode* getPart(vector<int>& nums, int left, int right) {
        if(left > right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* parent = new TreeNode(nums[mid]);
        parent->left = getPart(nums, left, mid-1);
        parent->right = getPart(nums, mid+1, right);
        return parent;
    }
};


// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0)
//             return NULL;
//         if(len == 1)
//             return new TreeNode(nums[0]);
//         int mid = len/2;
//         // cout << mid << endl;
//         // cout << nums[mid] << endl;
//         TreeNode* tmp = new TreeNode(nums[mid]);
//         vector<int> l;
//         l.assign(nums.begin(), nums.begin()+mid);
//         vector<int> r;
//         r.assign(nums.begin()+mid+1, nums.end());
//         tmp->left = sortedArrayToBST(l);
//         tmp->right = sortedArrayToBST(r);
//         return tmp;
//     }
// };