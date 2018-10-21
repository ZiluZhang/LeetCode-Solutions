// Maximum Subarray
// 遍历一次，如果前一位置记录的和小于0，那么不要，只用自己；否则用前一位置+自己

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> tmp(len, 0);
        int res = nums[0];
        tmp[0] = nums[0];
        for(int i = 1; i < len; i++) {
            tmp[i] = tmp[i-1] < 0 ? nums[i]: tmp[i-1] + nums[i];
            res = res < tmp[i] ? tmp[i]: res;
        }
        return res;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int i = 0, sum = 0;
//         int maxsum = nums[0];
//         for(i = 0; i < len; i++)
//         {
//             sum += nums[i];
//             // cout << maxsum << " " << sum << endl;
//             if(sum > maxsum)
//                 maxsum = sum;
//             if(sum < 0)
//                 sum = 0;
//             // cout << maxsum << " " << sum << endl;
//         }
//         return maxsum;
//     }
// };