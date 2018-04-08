class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1)
            return 1;
        int k = primes.size();
        vector<int> t(k, 0);
        vector<int> ans(n, INT_MAX);
        ans[0] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < k; j++)
                ans[i] = min(primes[j] * ans[t[j]], ans[i]);
            for(int j = 0; j < k; j++)
                if(ans[i] == primes[j] * ans[t[j]])
                    t[j]++;
        }
        // for(int i = 0; i < n; i++)
        //     cout << ans[i] << endl;
        return ans[n-1];
    }
};
// 1,2,4,7,8,13,14,16,