class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2,0);
        int mask = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            mask ^= nums[i];
        int l = mask & (~(mask-1));
        for(int i = 0; i < len; i++)
        {
            if((l & nums[i]) != 0)
                res[0] ^= nums[i];
            else
                res[1] ^= nums[i];
        }
        return res;
    }
};