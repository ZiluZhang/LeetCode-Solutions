class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> tmp = vector<int>(i);
            tmp[0] = 1;
            tmp[i-1] = 1;
            if(ans.size() == 0)
            {
                ans.push_back(tmp);
                continue;
            }
            int prev = ans.size() - 1;
            for(int j = 1; j < i-1; j++)
                tmp[j] = ans[prev][j-1] + ans[prev][j];
            ans.push_back(tmp);
        }
        return ans;
    }
};