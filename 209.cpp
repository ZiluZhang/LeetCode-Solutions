// Minimum Size Subarray Sum
// sliding window!!!
// 右指针一直右移到满足条件，然后左指针右移直到不满足，过程中一直update result
// 注意最外层循环条件是右指针不过界

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int sum = 0;
        int left = 0, right = 0;
        int res = len+1;
        while(left <= right && right < len) {
            while(sum < s && right < len){
                sum += nums[right++];
            }
            while(sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res==len+1?0:res;
    }
};