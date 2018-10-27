// Longest Consecutive Sequence
// unordered_map是哈希！好用！
// 找连续序列


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        unordered_map<int, int> cnt;
        int res = 0;
        for(int i = 0; i < len; i++) {
            if(!cnt.count(nums[i])) {
                int left = cnt.count(nums[i] - 1) ? cnt[nums[i]-1] : 0;
                int right = cnt.count(nums[i] + 1) ? cnt[nums[i]+1] : 0;
                int cur = left + right + 1;
                cnt.insert(pair<int,int>(nums[i], cur));
                res = max(res, cur);
                cnt[nums[i]-left] = cur;
                cnt[nums[i]+right] = cur;
            }
        }
        return res;
    }
};