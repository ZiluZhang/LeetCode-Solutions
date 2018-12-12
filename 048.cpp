// Rotate Image
// 
// 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 1) return;
        for(int i = 0; i < n/2; i++) {
            int k = n - i;
            for(int j = i; j < k-1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[k-1-j+i][i];
                matrix[k-1-j+i][i] = matrix[k-1][k-1-j+i];
                matrix[k-1][k-1-j+i] = matrix[j][k-1];
                matrix[j][k-1] = tmp;
            }
        }
        return;
    }
};