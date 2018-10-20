// Combination Sum
// 递归（start idx, sum, current vec, all nums）
// 每一个，取或不取：取，再递归下一个（如果能重复用，就是还是这个），再不取，再递归
// 如果达到要求，就存到res里
// vector.push_back(item), vector.pop_back()
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        vector<int> tmp;
        help(0, target, tmp, candidates);
        return res;
    }
    
    void help(int begin, int s, vector<int>& cur, vector<int>& candidates) {
        int len = candidates.size();
        if(s > 0) {
            for(int i = begin; i < len && candidates[i] <= s; i++) {
                cur.push_back(candidates[i]);
                help(i, s-candidates[i], cur, candidates);
                cur.pop_back();
            }
        }
        else if(s == 0) {
            res.push_back(cur);
        }
        return;
    }
};

// class Solution {
// public:
//     vector<vector<int>> results;
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int len = candidates.size();
//         sort(candidates.begin(), candidates.end());
//         vector<int> tmp;
//         getRes(tmp, candidates, target, 0, len);
//         return results;
//     }
    
//     void getRes(vector<int>  , vector<int>& candidates, int target, int start, int len)
//     {
//         if(target > 0)
//         {
//             for(int i = start; i < len && target >= candidates[i]; i++)
//             {
//                 cur.push_back(candidates[i]);
//                 getRes(cur, candidates, target - candidates[i], i, len);
//                 cur.pop_back();
//             }
//         }
//         else if(target == 0)
//             results.push_back(cur);
//         return;
//     }
// };

// // public class Solution {
// //     public List<List<Integer>> combinationSum(int[] candidates, int target) {
// //     	Arrays.sort(candidates);
// //         List<List<Integer>> result = new ArrayList<List<Integer>>();
// //         getResult(result, new ArrayList<Integer>(), candidates, target, 0);
        
// //         return result;
// //     }
    
// //     private void getResult(List<List<Integer>> result, List<Integer> cur, int candidates[], int target, int start){
// //     	if(target > 0){
// //     		for(int i = start; i < candidates.length && target >= candidates[i]; i++){
// //     			cur.add(candidates[i]);
// //     			getResult(result, cur, candidates, target - candidates[i], i);
// //     			cur.remove(cur.size() - 1);
// //     		}//for
// //     	}//if
// //     	else if(target == 0 ){
// //     		result.add(new ArrayList<Integer>(cur));
// //     	}//else if
// //     }
// // }