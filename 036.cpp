// Valid Sudoku
// 查每一行，查每一列，查每一个方格
// 主要是方格中元素的行列表示

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check each row
        for(int i = 0; i < 9; i++) {
            vector<bool> used(9, false);
            for(int j = 0; j < 9; j++) {
                if(!checkuse(used, board[i][j]))
                    return false;
            }
        }
        // check each column
        for(int j = 0; j < 9; j++) {
            vector<bool> used(9, false);
            for(int i = 0; i < 9; i++) {
                if(!checkuse(used, board[i][j]))
                    return false;
            }
        }
        // check each square
        for(int t = 0; t < 9; t++) {
            vector<bool> used(9, false);
            for(int s = 0; s < 9; s++) {
                int i = (t / 3) * 3 + s / 3;
                int j = (t % 3) * 3 + s % 3;
                if(!checkuse(used, board[i][j]))
                    return false;
            }
        }
        return true;
    }
    
    // if already used, return false;
    // else, set as used, return true
    bool checkuse(vector<bool>& cur, char tmp) {
        if(tmp == '.') return true;
        if(cur[tmp-'1']) return false;
        else {
            cur[tmp-'1'] = true;
            return true;
        }
    }
};