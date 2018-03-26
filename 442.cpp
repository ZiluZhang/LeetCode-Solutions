class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // map<int, int> cnt;
        // int len = nums.size();
        // vector<int> dup;
        // for(int i = 0; i < len; i++)
        // {
        //     int cur = nums[i];
        //     if(cnt.find(cur) == cnt.end())
        //         cnt.insert(pair<int, int>(cur, 1));
        //     else
        //         dup.push_back(cur);
        // }
        int len = nums.size();
        vector<int> dup;
        for(int i = 0; i < len; i++)
        {
            int cur = abs(nums[i]);
            if(nums[cur-1] < 0)
                dup.push_back(cur);
            else
                nums[cur-1] = -nums[cur-1];
        }
        return dup;
    }
};