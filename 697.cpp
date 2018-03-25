class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        map<int, vector<int>> cnt;
        vector<int> tmp;
        int maxfre = 0;
        int minlen = len;
        for(int i = 0; i < len; i++)
        {
            if(cnt.find(nums[i]) == cnt.end())
            {
                cnt.insert(pair<int, vector<int>>(nums[i], {1, i, i}));
                tmp.push_back(nums[i]);
            }
            else
            {
                cnt[nums[i]][0]++;
                cnt[nums[i]][2] = i;
            }
        }
        int len2 = cnt.size();
        cout << len2 << endl;
        for(int i = 0; i < len2; i++)
        {
            int j = tmp[i];
            if(cnt[j][0] > maxfre)
            {
                maxfre = cnt[j][0];
                minlen = cnt[j][2] - cnt[j][1] + 1;
            }
            else if(cnt[j][0] == maxfre)
            {
                int t = cnt[j][2] - cnt[j][1] + 1;
                minlen = t < minlen ? t : minlen;
            }
        }
        cout << maxfre << endl;
        return minlen;
    }
};