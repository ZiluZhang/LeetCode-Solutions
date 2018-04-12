class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int len = matrix.size();
        if(len == 0)
            return res;
        int wid = matrix[0].size();
        int rnd = (min(len, wid) + 1)/2;
        for(int k = 0; k < rnd; k++)
        {
            int i = k;
            int j = k;
            if(k*2+1 == len)
            {
                // i in the middle, only 1 row
                for(j = k; j < wid-k; j++)
                    res.push_back(matrix[i][j]);
                break;
            }
            else if(k*2+1 == wid)
            {
                // j in the middle, only 1 column
                for(i = k; i < len-k; i++)
                    res.push_back(matrix[i][j]);
                break;
            }
            for(j = k; j < wid-k; j++)
                res.push_back(matrix[i][j]);
            j = wid - k - 1;
            for(i = k+1; i < len-k-1; i++)
                res.push_back(matrix[i][j]);
            i = len - k - 1;
            for(j = wid-k-1; j > k; j--)
                res.push_back(matrix[i][j]);
            j = k;
            for(i = len-k-1; i > k; i--)
                res.push_back(matrix[i][j]);
        }
        return res;
    }
};