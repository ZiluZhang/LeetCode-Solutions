class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        int max = -1;
        int idx = -1;
        for(int i = 0; i < len; i++)
        {
            if(max < nums[i])
            {
                idx = i;
                max = nums[i];
            }
        }
        cout << max << endl;
        cout << idx << endl;
        for(int i = 0; i < len; i++)
            if(max != nums[i] && max < nums[i] * 2)
                return -1;
        return idx;
    }
};