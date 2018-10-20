// Find First and Last Position of Element in Sorted Array
// 首先用二分法找到这个元素，记录位置
// 左边到该位置，二分查找边界
// 该位置到右边，二分查找边界

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return {-1, -1};
        int left = 0, right = len-1;
        bool found = false;
        int idx = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                found = true;
                idx = mid;
                break;
            }
            if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        if(!found) return {-1, -1};
        // cout << idx << endl;
        vector<int> res(2, idx);
        left = 0;
        right = idx-1;
        while(left <= right && nums[right] == target) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                res[0] = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        left = idx+1;
        right = len-1;
        while(left <= right && nums[left] == target) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                res[1] = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return res;
    }
};