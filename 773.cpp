// Sliding Puzzle
// 华容道，BFS
// 
// 


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2;
        int n = 3;
        vector<vector<int>> correct = {{1,2,3},{4,5,0}};
        if(board == correct) return 0;
        set<vector<vector<int>>> cnt;
        queue<pair<vector<vector<int>>, int>> q;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0) {
                    q.push({board, i*n+j});
                    break;
                }
            }
        }
        int res = 0;
        while(!q.empty()) {
            res++;
            for(int k = q.size(); k > 0; k--) {
                auto b = q.front().first;
                int x = q.front().second / n, y = q.front().second % n;
                q.pop();
                for(auto d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    auto cur = b; // 这里要定义一个新的，要不然原有的就被改了
                    swap(cur[x][y], cur[nx][ny]);
                    if(cur == correct) return res;
                    if(cnt.count(cur)) continue;
                    q.push({cur, nx*n+ny});
                    cnt.insert(cur);
                }
            }
        }
        return -1;
    }
};