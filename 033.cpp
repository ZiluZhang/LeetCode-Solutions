// Search in Rotated Sorted Array
// 中间到左边或中间到右边是有序的
// 变形二分！
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            // then mid~right is ascending
            else if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
            // then left~mid is descending
            else {
                if(nums[left] <= target && target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int len = nums.size();
//         int l = 0;
//         int r = len-1;
//         while(l < r)
//         {
//             int mid = (l + r)/2;
//             if(nums[mid] > nums[r])
//                 l = mid+1;
//             else
//                 r = mid;
//         }
//         int idx = l;
//         l = 0;
//         r = len-1;
//         while(l <= r)
//         {
//             int mid = (l + r)/2;
//             int cur = (mid + idx) % len;
//             if(nums[cur] == target)
//                 return cur;
//             else if(nums[cur] < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         return -1;
//     }
// };