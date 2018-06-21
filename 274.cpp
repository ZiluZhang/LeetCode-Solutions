class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        int cnt = len;
        for(int i = 0; i < len; i++)
        {
            if(citations[i] >= cnt)
                return cnt;
            else
                cnt--;
        }
        return 0;
    }
};