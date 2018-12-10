// Sparse Matrix Multiplication

// 直接来
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        if(m == 0) return {};
        int n = A[0].size();
        int k = B[0].size();
        vector<vector<int>> res(m, vector<int>(k,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < k; j++) {
                for(int t = 0; t < n; t++) {
                    if(A[i][t] != 0)
                        res[i][j] += A[i][t] * B[t][j];
                }
            }
        }
        return res;
    }
};


// 把A中非零元素都存下来
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        if(m == 0) return {};
        int n = A[0].size();
        int k = B[0].size();
        vector<vector<int>> res(m, vector<int>(k,0));
        vector<vector<pair<int,int>>> val(m, vector<pair<int,int>>());
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j])
                    val[i].push_back({j, A[i][j]});
            }
        }
        for(int i = 0; i < m; i++) {
            int num = val[i].size();
            for(int j = 0; j < num; j++) {
                int t = val[i][j].first;
                int v = val[i][j].second;
                for(int l = 0; l < k; l++) {
                    res[i][l] += v * B[t][l];
                }
            }
        }
        return res;
    }
};