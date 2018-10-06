class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        getPer(nums, 0, results);
        return results;
    }
    
    void getPer(vector<int>& nums, int start, vector<vector<int>>& r)
    {
        if(start >= nums.size())
        {
            r.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            getPer(nums, start+1, r);
            swap(nums[start], nums[i]);
        }
        return;
    }
};

// vector<vector<int> > permute(vector<int> &num) {
// 	    vector<vector<int> > result;
	    
// 	    permuteRecursive(num, 0, result);
// 	    return result;
//     }
    
//     // permute num[begin..end]
//     // invariant: num[0..begin-1] have been fixed/permuted
// 	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
// 		if (begin >= num.size()) {
// 		    // one permutation instance
// 		    result.push_back(num);
// 		    return;
// 		}
		
// 		for (int i = begin; i < num.size(); i++) {
// 		    swap(num[begin], num[i]);
// 		    permuteRecursive(num, begin + 1, result);
// 		    // reset
// 		    swap(num[begin], num[i]);
// 		}
//     }