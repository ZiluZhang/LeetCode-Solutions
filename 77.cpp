class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combine(int n, int k) {
        if(n<=0 || n<k || k<=0) return results;
        vector<int> prev;
        dfs(n, k, 1, 0, prev);
        return results;
    }
    void dfs(int n, int k, int start, int cur, vector<int> p) {
        if(cur == k)
        {
            results.push_back(p);
            return;
        }
        for(int i = start; i <= n-(k-cur)+1; i++)
        {
            p.push_back(i);
            dfs(n, k, i+1, cur+1, p);
            p.pop_back();
        }
    }
};
// public List<List<Integer>> combine(int n, int k) {
//         List<List<Integer>> result = new ArrayList<>();
//         List<Integer> path = new ArrayList<>();
//         dfs(n, k, 1, 0, path, result);
//         return result;
//     }
//     // start，开始的数, cur，已经选择的数目
//     private static void dfs(int n, int k, int start, int cur,
//                             List<Integer> path, List<List<Integer>> result) {
//         if (cur == k) {
//             result.add(new ArrayList<>(path));
//         }
//         for (int i = start; i <= n; ++i) {
//             path.add(i);
//             dfs(n, k, i + 1, cur + 1, path, result);
//             path.remove(path.size() - 1);
//         }
//     }