class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxpre = nums[0];
        int minpre = nums[0];
        int maximum = maxpre;
        for(int i = 1; i < len; i++)
        {
            int m1 = max(max(maxpre*nums[i], minpre*nums[i]), nums[i]);
            int m2 = min(min(maxpre*nums[i], minpre*nums[i]), nums[i]);
            maxpre = m1;
            minpre = m2;
            maximum = max(maxpre, maximum);
        }
        return maximum;
    }
};