class Solution {
public:
    vector<vector<int>> thisgrid;
    vector<vector<bool>> tmp;
    int len;
    int wid;
    int island(int a, int b)
    {
        if(a < 0 || a >= len || b < 0 || b >= wid || tmp[a][b] || thisgrid[a][b] == 0)
            return 0;
        tmp[a][b] = true;
        return 1 + island(a-1, b) + island(a+1, b) + island(a, b-1) + island(a, b+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        thisgrid = grid;
        len = grid.size();
        if(len == 0)
            return 0;
        wid = grid[0].size();
        vector<vector<bool>> a(len, vector<bool>(wid));
        tmp = a;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < wid; j++)
                tmp[i][j] = false;
        int ans = -1;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < wid; j++)
            {
                int cnt = island(i, j);
                ans = cnt > ans ? cnt : ans;
            }
        return ans;
    }
};