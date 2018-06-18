class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> tmp;
        dfs(k, n, 1, 0, 0, tmp, results);
        return results;
    }
    void dfs(int k, int n, int start, int sum, int count, vector<int>& cur, vector<vector<int>>& res)
    {
        if(sum > n)
            return;
        if(sum == n && count == k)
        {
            res.push_back(cur);
            // return;
        }
        for(int i = start; i <= 9; i++)
        {
            if(find(cur.begin(), cur.end(), i) != cur.end())
                return;
            cur.push_back(i);
            dfs(k, n, start+1, sum+i, count+1, cur, res);
            cur.pop_back();
        }
        return;
    }
};

// vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> res;
//         vector<int> out;
//         dfs(k, n, 1, 0, 0, out, res);
//         return res;
//     }
//     void dfs(int k, int n, int start, int sum, int count, vector<int>& out, vector<vector<int>>& res) {
//         if (sum > n)
//             return;
//         if (sum == n && count == k) 
//             res.push_back(out);
//         for (int i = start; i <= 9; i++) {
//             if (find(out.begin(), out.end(), i) != out.end())
//                 return;
//             out.push_back(i);
//             dfs(k, n, start + 1, sum + i, count + 1, out, res);
//             out.pop_back();
//         }
//     }