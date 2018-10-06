class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        dfs(nums, 0, nums.size(), results);
        return results;
    }
    
    void dfs(vector<int> nums, int i, int j, vector<vector<int>>& r)
    {
        if(i == j-1)
        {
            r.push_back(nums);
            return;
        }
        for(int k = i; k < j; k++)
        {
            if(i != k && nums[i] == nums[k])
                continue;
            swap(nums[i], nums[k]);
            dfs(nums, i+1, j, r);
        }
    }
};

// void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
//         if (i == j-1) {
//             res.push_back(num);
//             return;
//         }
//         for (int k = i; k < j; k++) {
//             if (i != k && num[i] == num[k]) continue;
//             swap(num[i], num[k]);
//             recursion(num, i+1, j, res);
//         }
//     }
//     vector<vector<int> > permuteUnique(vector<int> &num) {
//         sort(num.begin(), num.end());
//         vector<vector<int> >res;
//         recursion(num, 0, num.size(), res);
//         return res;
//     }