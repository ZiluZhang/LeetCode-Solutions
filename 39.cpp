class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                getRes(cur, candidates, target - candidates[i], i, len);
                cur.pop_back();
            }
        }
        else if(target == 0)
            results.push_back(cur);
        return;
    }
};

// public class Solution {
//     public List<List<Integer>> combinationSum(int[] candidates, int target) {
//     	Arrays.sort(candidates);
//         List<List<Integer>> result = new ArrayList<List<Integer>>();
//         getResult(result, new ArrayList<Integer>(), candidates, target, 0);
        
//         return result;
//     }
    
//     private void getResult(List<List<Integer>> result, List<Integer> cur, int candidates[], int target, int start){
//     	if(target > 0){
//     		for(int i = start; i < candidates.length && target >= candidates[i]; i++){
//     			cur.add(candidates[i]);
//     			getResult(result, cur, candidates, target - candidates[i], i);
//     			cur.remove(cur.size() - 1);
//     		}//for
//     	}//if
//     	else if(target == 0 ){
//     		result.add(new ArrayList<Integer>(cur));
//     	}//else if
//     }
// }