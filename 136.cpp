class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> cnt;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(cnt.find(nums[i]) == cnt.end())
                cnt.insert(pair<int, int>(nums[i], 1));
            else
                cnt[nums[i]]++;
        }
        for(int i = 0; i < len; i++)
            if(cnt[nums[i]] == 1)
                return nums[i];
    }
};