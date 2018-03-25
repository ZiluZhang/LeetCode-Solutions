class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int len = nums.size();
        map<int, int> ans;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(i == j)
                    continue;
                if(nums[i] - nums[j] == k && ans.find(nums[j]) == ans.end())
                    ans.insert(pair<int, int>(nums[j], nums[i]));
                if(nums[j] - nums[i] == k && ans.find(nums[i]) == ans.end())
                    ans.insert(pair<int, int>(nums[i], nums[j]));
            }
        }
        return ans.size();
    }
};