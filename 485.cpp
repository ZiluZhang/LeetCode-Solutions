class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int max = 0;
        int i = 0;
        while(i < len)
        {
            int cnt = 0;
            while(i < len && nums[i] == 0)
                i++;
            while(i < len && nums[i] == 1)
            {
                i++;
                cnt++;
            }
            if(cnt > max)
                max = cnt;
        }
        return max;
    }
};