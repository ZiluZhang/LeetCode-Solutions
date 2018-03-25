class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int len = nums.size();
        int i = 0;
        int cnt = len;
        while(i < len && nums[i] == tmp[i])
        {
            cnt--;
            i++;
        }
        if(i == len)
            return cnt;
        i = len-1;
        while(i >= 0 && nums[i] == tmp[i])
        {
            cnt--;
            i--;
        }
        return cnt;
    }
};