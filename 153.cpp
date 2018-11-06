// Find Minimum in Rotated Sorted Array
// 无重复元素
// 二分，如果left<mid就查右半边，否则查左半边
// 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return nums[0];
        int left = 0, right = len-1;
        if(nums[left] > nums[right]) {
            while(left != right-1) {
                int mid = left + (right - left) / 2;
                if(nums[left] < nums[mid]) left = mid;
                else right = mid;
            }
            return min(nums[left], nums[right]);
        }
        return nums[0];
    }
};


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int len = nums.size();
//         int l = 0;
//         int r = len-1;
//         while(l < r)
//         {
//             if(nums[l] < nums[r])
//                 return nums[l];
//             int mid = (l + r)/2;
//             if(nums[mid] >= nums[r])
//                 l = mid + 1;
//             else
//                 r = mid;
//         }
//         return nums[l];
//     }
// };