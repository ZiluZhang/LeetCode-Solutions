class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> res(n,row);
        int rnd = (n+1)/2;
        int idx = 1;
        for(int k = 0; k < rnd; k++)
        {
            int i = k;
            int j = k;
            if(k*2+1 == n)
            {
                res[k][k] = idx;
                break;
            }
            for(j = k; j < n - k - 1; j++)
            {
                res[i][j] = idx;
                idx++;
            }
            for(i = k; i < n - k - 1; i++)
            {
                res[i][j] = idx;
                idx++;
            }
            for(j = n-k-1; j > k; j--)
            {
                res[i][j] = idx;
                idx++;
            }
            for(i = n-k-1; i > k; i--)
            {
                res[i][j] = idx;
                idx++;
            }
        }
        return res;
    }
};