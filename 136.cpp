class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int a = 0;
        for(int i = 0; i < len; i++)
            a ^= nums[i];
        return a;
    }
};