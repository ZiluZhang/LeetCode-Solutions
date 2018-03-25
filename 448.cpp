class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> cnt;
        for(int i = 0; i < len; i++)
            cnt.push_back(i+1);
        for(int i = 0; i < len; i++)
            cnt[nums[i]-1] = -1;
        int i = 0, j = 0;
        while(j < len)
        {
            if(cnt[j] != -1)
            {
                int tmp = cnt[i];
                cnt[i] = cnt[j];
                cnt[j] = tmp;
                i++;
            }
            j++;
        }
        j = len-1;
        while(j >= 0 && cnt[j] == -1)
        {
            cnt.pop_back();
            j--;
        }
        return cnt;
    }
};