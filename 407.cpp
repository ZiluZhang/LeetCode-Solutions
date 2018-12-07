// Trapping Rain Water II
// 用优先队列，定义最小堆<class, vector<class>, greater<class>>
// 从边界开始，广搜
// 存一个mx其实是local maximum，这样遇到一个旁边的小的位置，就知道到底能存多少水
// https://www.youtube.com/watch?v=cJayBq38VYw

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() == 0) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        int res = 0;
        int mx = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    q.push(pair<int, int>(heightMap[i][j], i*n+j));
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            auto t = q.top();
            q.pop();
            int h = t.first;
            int r = t.second / n;
            int c = t.second % n;
            mx = max(mx, h);
            for(int i = 0; i < dir.size(); i++) {
                int x = r + dir[i][0], y = c + dir[i][1];
                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if(heightMap[x][y] < mx) res += mx - heightMap[x][y];
                q.push({heightMap[x][y], x*n+y});
            }
        }
        return res;
    }
};