class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int i = 0, sum = 0;
        int maxsum = nums[0];
        for(i = 0; i < len; i++)
        {
            sum += nums[i];
            // cout << maxsum << " " << sum << endl;
            if(sum > maxsum)
                maxsum = sum;
            if(sum < 0)
                sum = 0;
            // cout << maxsum << " " << sum << endl;
        }
        return maxsum;
    }
};