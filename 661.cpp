class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int len = M.size();
        int wid = M[0].size();
        vector<vector<int>> ans(len, vector<int>(wid));
        vector<vector<int>> tmp(len+2, vector<int>(wid+2));
        for(int i = 0; i < len; i++)
            for(int j = 0; j < wid; j++)
            {
                int cnt = 0;
                int sum = 0;
                for(int k = -1; k < 2; k++)
                    for(int l = -1; l < 2; l++)
                        if(0 <= i+k && i+k < len && 0 <= j+l && j+l < wid)
                        {
                            sum += M[i+k][j+l];
                            cnt ++;
                        }
                if(cnt == 0)
                    cout << i << " " << j << endl;
                ans[i][j] = sum / cnt;
            }
        return ans;
    }
};