class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1690,0);
        ans[0] = 1;
        int t0 = 0, t1 = 0, t2 = 0;
        for(int i = 1; i < n; i++)
        {
            ans[i] = min(ans[t0] * 2, min(ans[t1]* 3, ans[t2] * 5));
            if(ans[i] == ans[t0]*2)
                t0++;
            if(ans[i] == ans[t1]*3)
                t1++;
            if(ans[i] == ans[t2]*5)
                t2++;
        }
        return ans[n-1];
    }
};