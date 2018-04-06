class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> cnt(len, 0);
        int max = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && cnt[i] < cnt[j])
                    cnt[i] = cnt[j];
            }
            cnt[i]++;
            if(cnt[i] > max)
            {
                max = cnt[i];
            }
        }
        return max;
    }
};