class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        while(k > 0)
        {
            int tmp = nums[len-1];
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
            k--;
        }
        return;
    }
};