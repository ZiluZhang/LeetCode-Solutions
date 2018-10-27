// Kth Largest Element in an Array
// 快排！
// 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0, right = len-1;
        while(true) {
            int tmp = fastsort(nums, left, right);
            if(tmp == k-1) return nums[tmp];
            else if(tmp < k-1) left = tmp + 1;
            else right = tmp - 1;
        }
        return -1;
    }
    
    int fastsort(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while(l <= r) {
            if(nums[l] < pivot && pivot < nums[r]) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};