class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0, j = 0;
        while(i < len && j < len)
        {
            while(j < len && nums[j] == val)
                j++;
            if(j >= len)
                break;
            else
            {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                i += 1;
                j += 1;
            }
        }
        return i;
    }
};