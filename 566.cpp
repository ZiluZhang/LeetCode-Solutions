class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0)
            return nums;
        int prev_r = nums.size();
        int prev_c = nums[0].size();
        if(prev_r * prev_c != r * c)
            return nums;
        cout << prev_r << prev_c << endl;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < prev_r; i++)
        {
            for(int j = 0; j < prev_c; j++)
            {
                int tmp = i * prev_c + j;
                cout << tmp << endl;
                ans[tmp/c][tmp%c] = nums[i][j];
            }
        }
        return ans;
    }
};