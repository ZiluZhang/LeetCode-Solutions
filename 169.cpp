class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        map<int, int> cnt;
        for(int i = 0; i < len; i++)
        {
            int times = 0;
            map<int, int>::iterator f = cnt.find(nums[i]);
            if(f != cnt.end())
                cnt[nums[i]] += 1;
            else
                cnt.insert(pair<int, int>(nums[i], 1));
            if(cnt[nums[i]] > len/2)
                return nums[i];
        }
        return 0;
    }
};