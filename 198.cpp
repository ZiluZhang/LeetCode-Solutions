class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        cout << len << endl;
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        // if(len == 2)
        //     return max(nums[0]+nums[2], nums[1]);
        vector<int> m(len,0);
        m[0] = nums[0];
        m[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++)
            m[i] = max(m[i-1], m[i-2]+nums[i]);
        return m[len-1];
    }
};