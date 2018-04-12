class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        int k = pow(2,len) - 1;
        while(k >= 0)
        {
            int cur = k;
            int idx = 0;
            vector<int> tmp;
            while(cur > 0)
            {
                if(cur % 2 != 0)
                    tmp.push_back(nums[idx]);
                cur /= 2;
                idx++;
            }
            res.push_back(tmp);
            k--;
        }
        return res;
    }
};