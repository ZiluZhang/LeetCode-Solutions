// Word Search
// 滑雪问题！
// 剪枝：如果都查完了、如果x/y超出了范围、如果visit过、如果不等
// 先设当前位置visit过，拿到四个方向结果，再设回未visit，再return结果

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = board.size();
        if(word.length() == 0) return true;
        if(len <= 0) return false;
        int wid = board[0].size();
        vector<bool> tmp(wid, false);
        vector<vector<bool>> visited(len, tmp);
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < wid; j++) {
                if(ski(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool ski(vector<vector<char>>& board, string word, 
             int idx, int x, int y, vector<vector<bool>>& visited) {
        if(idx >= word.length()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(visited[x][y]) return false;
        if(word[idx] != board[x][y]) return false;
        visited[x][y] = true;
        bool tmp = ski(board, word, idx+1, x+1, y, visited)
            || ski(board, word, idx+1, x-1, y, visited)
            || ski(board, word, idx+1, x, y+1, visited)
            || ski(board, word, idx+1, x, y-1, visited);
        visited[x][y] = false;
        return tmp;
    }
};