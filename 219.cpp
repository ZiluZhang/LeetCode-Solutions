class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> prev;
        for(int i = 0; i < len; i++)
        {
            if(prev.find(nums[i]) != prev.end() && i - prev[nums[i]] <= k)
                return true;
            if(prev.find(nums[i]) != prev.end())
                prev[nums[i]] = i;
            else
                prev.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};