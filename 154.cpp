// Find Minimum in Rotated Sorted Array II
// 有重复元素
// 二分法如果left mid right都相等，二分法就崩了！
// 判断如果left=mid就右移left，这样最差情况O(n)
// 注意right=mid不要加一


class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len-1;
        while(left < right - 1) {
            if(nums[left] < nums[right]) return nums[left];
            int mid = left + (right - left) / 2;
            if(nums[left] < nums[mid]) left = mid+1;
            else if(nums[left] > nums[mid]) right = mid;
            else ++left;
        }
        return min(nums[left], nums[right]);
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
//             if(nums[mid] > nums[r])
//                 l = mid + 1;
//             else if(nums[mid] < nums[r])
//                 r = mid;
//             else
//                 r--;
//         }
//         return nums[l];
//     }
// };