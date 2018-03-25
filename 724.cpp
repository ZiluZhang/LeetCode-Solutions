class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return -1;
        if(len == 1)
            return 0;
        vector<int> sum(len, 0);
        sum[0] = nums[0];
        for(int i = 1; i < len; i++)
            sum[i] = sum[i-1] + nums[i];
        for(int i = 0; i < len; i++)
        {
            if(i == 0 && sum[len-1] - sum[i] == 0)
                return i;
            if(sum[i-1] == sum[len-1] - sum[i])
                return i;
        }
        return -1;
    }
};