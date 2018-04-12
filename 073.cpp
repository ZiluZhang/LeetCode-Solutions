class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len == 0)
            return;
        int wid = matrix[0].size();
        bool r = false;
        bool c = false;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < wid; j++)
                if(matrix[i][j] == 0)
                {
                    if(i == 0)
                        r = true;
                    if(j == 0)
                        c = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for(int i = 1; i < len; i++)
            for(int j = 1; j < wid; j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
        if(r)
            for(int j = 0; j < wid; j++)
                matrix[0][j] = 0;
        if(c)
            for(int i = 0; i < len; i++)
                matrix[i][0] = 0;
        return;
    }
};