// Permutations
// 深搜，其实也可以用nex permutation的方法
// 需要维护一个used数组，存哪些用过哪些没用过
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<bool> used(len, false);
        vector<int> tmp;
        help(tmp, nums, used);
        return res;
    }
    
    void help(vector<int>& cur, vector<int>& nums, vector<bool>& used) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            help(cur, nums, used);
            cur.pop_back();
            used[i] = false;
        }
        return;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> results;
//         getPer(nums, 0, results);
//         return results;
//     }
    
//     void getPer(vector<int>& nums, int start, vector<vector<int>>& r)
//     {
//         if(start >= nums.size())
//         {
//             r.push_back(nums);
//             return;
//         }
//         for(int i = start; i < nums.size(); i++)
//         {
//             swap(nums[start], nums[i]);
//             getPer(nums, start+1, r);
//             swap(nums[start], nums[i]);
//         }
//         return;
//     }
// };

// // vector<vector<int> > permute(vector<int> &num) {
// // 	    vector<vector<int> > result;
	    
// // 	    permuteRecursive(num, 0, result);
// // 	    return result;
// //     }
    
// //     // permute num[begin..end]
// //     // invariant: num[0..begin-1] have been fixed/permuted
// // 	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
// // 		if (begin >= num.size()) {
// // 		    // one permutation instance
// // 		    result.push_back(num);
// // 		    return;
// // 		}
		
// // 		for (int i = begin; i < num.size(); i++) {
// // 		    swap(num[begin], num[i]);
// // 		    permuteRecursive(num, begin + 1, result);
// // 		    // reset
// // 		    swap(num[begin], num[i]);
// // 		}
// //     }