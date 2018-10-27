// Number of Islands
// 维护一个visited数组，如果当前是岛屿并且没有visit，就深搜visit和它相连所有的
// 


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int len = grid.size();
        if(len == 0) return 0;
        int wid = grid[0].size();
        vector<bool> tmp(wid, false);
        vector<vector<bool>> visited(len, tmp);
        int res = 0;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < wid; j++) {
                if(grid[i][j] == '1' && (!visited[i][j])) {
                    visitIsland(i, j, len, wid, visited, grid);
                    res++;
                }
            }
        }
        return res;
    }
    
    void visitIsland(int x, int y, int len, int wid, 
                     vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        if(x < 0 || x >= len) return;
        if(y < 0 || y >= wid) return;
        if(grid[x][y] != '1' || visited[x][y]) return;
        visited[x][y] = true;
        visitIsland(x+1, y, len, wid, visited, grid);
        visitIsland(x-1, y, len, wid, visited, grid);
        visitIsland(x, y+1, len, wid, visited, grid);
        visitIsland(x, y-1, len, wid, visited, grid);
        return;
    }
};