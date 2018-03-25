class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        int tmp = -1;
        for(int i = 0; i < len-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(tmp != -1)
                    return false;
                tmp = i;
            }
        }
        if(tmp == -1 || tmp == 0 || tmp == len-2)
            return true;
        if(nums[tmp-1] <= nums[tmp+1] || nums[tmp] <= nums[tmp+2])
            return true;
        return false;
    }
};