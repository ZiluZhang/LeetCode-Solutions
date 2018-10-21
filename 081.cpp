// Search in Rotated Array II
// 存在重复元素，不能保证左半边/右半边单调
// 如果严格大于/小于中间元素，依然能保证单调
// 如果等于中间元素，就把这个指针移一位，相当于跳过这个重复数
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return false;
        int left = 0, right = len-1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[mid] > nums[right]){
                if(nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else right--;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int len = nums.size();
//         int l = 0;
//         int r = len-1;
//         while(l <= r)
//         {
//             int mid = (l + r) / 2;
//             if(nums[mid] == target)
//                 return true;
//             if(nums[l] < nums[mid])
//             {
//                 if(nums[l] <= target && target <= nums[mid])
//                     r =  mid;
//                 else
//                     l = mid + 1;
//             }
//             else if(nums[mid] < nums[r])
//             {
//                 if(nums[mid] <= target && target <= nums[r])
//                     l = mid + 1;
//                 else
//                     r = mid;
//             }
//             else
//             {
//                 if(nums[l] == nums[mid])
//                     l++;
//                 if(nums[r] == nums[mid])
//                     r--;
//             }
//         }
//         return false;
//     }
// };