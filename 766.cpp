class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int wid = matrix[0].size();
        for(int i = len-1; i >= 0; i--)
        {
            int tmp = matrix[i][0];
            for(int j = 1; j < wid; j++)
            {
                if(i+j >= len)
                    break;
                if(matrix[i+j][j] != tmp)
                    return false;
            }
        }
        for(int j = 1; j < wid; j++)
        {
            int tmp = matrix[0][j];
            for(int i = 1; i < len; i++)
            {
                if(i+j >= wid)
                    break;
                if(matrix[i][i+j] != tmp)
                    return false;
            }
        }
        return true;
    }
};