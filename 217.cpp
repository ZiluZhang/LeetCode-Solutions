class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        map<int, int> cnt;
        for(int i = 0; i < len; i++)
        {
            if(cnt.find(nums[i]) != cnt.end())
                return true;
            cnt.insert(pair<int, int>(nums[i], 1));
        }
        return false;
    }
};