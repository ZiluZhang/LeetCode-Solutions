class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        getRes(tmp, candidates, target, 0, len);
        return results;
    }
    
    void getRes(vector<int> cur, vector<int>& candidates, int target, int start, int len)
    {
        if(target > 0)
        {
            for(int i = start; i < len && target >= candidates[i]; i++)
            {
                cur.push_back(candidates[i]);
                getRes(cur, candidates, target - candidates[i], i+1, len);
                cur.pop_back();
            }
        }
        else if(target == 0)
        {
            if (find(results.begin(), results.end(), cur) == results.end())
                results.push_back(cur);
        }
        return;
    }
};