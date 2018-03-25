class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> sum = vector<int>(len);
        for(int i = 0; i < len; i++)
        {
            if(i == 0)
                sum[i] = nums[i];
            else
                sum[i] = nums[i] + sum[i-1];
        }
        int max = sum[k-1];
        cout << max << endl;
        for(int i = 0; i < len; i++)
        {
            if(i + k >= len)
                break;
            max = max >= sum[i+k]-sum[i] ? max : sum[i+k]-sum[i];
        }
        return (double)max/k;
    }
};