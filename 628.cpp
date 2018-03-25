class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int max1 = nums[0] * nums[1] * nums[len-1];
        int max2 = nums[len-1] * nums[len-2] * nums[len-3];
        if(max1 > max2)
            return max1;
        return max2;
    }
};