// Maximal Rectangle
// 每一行，当做084来做
// 
// 

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int len = matrix.size();
        if(len == 0) return 0;
        int wid = matrix[0].size();
        int res = 0;
        vector<int> height(wid+1, 0);
        for(int i = 0; i < len; i++) {
            stack<int> s;
            for(int j = 0; j < wid + 1; j++) {
                if(j < wid) height[j] = (matrix[i][j] == '1') ? height[j]+1 : 0;
                while(!s.empty() && height[s.top()] >= height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur] * (s.empty()? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
};