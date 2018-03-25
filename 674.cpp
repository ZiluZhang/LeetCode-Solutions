class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int max = 0;
        while(i < len)
        {
            int cnt = 1;
            while(i < len-1 && nums[i] < nums[i+1])
            {
                i++;
                cnt++;
            }
            max = cnt > max ? cnt : max;
            i++;
        }
        return max;
    }
};