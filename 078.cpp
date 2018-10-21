// Subsets
// 深搜，不能有重复元素，所以help函数里没有for循环

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return res;
        vector<int> tmp;
        help(0, len, nums, tmp);
        return res;
    }
    
    void help(int start, int len, vector<int>& nums, vector<int>& cur) {
        if(start >= len) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[start]);
        help(start+1, len, nums, cur);
        cur.pop_back();
        help(start+1, len, nums, cur);
        return;
    }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int len = nums.size();
//         vector<vector<int>> res;
//         int k = pow(2,len) - 1;
//         while(k >= 0)
//         {
//             int cur = k;
//             int idx = 0;
//             vector<int> tmp;
//             while(cur > 0)
//             {
//                 if(cur % 2 != 0)
//                     tmp.push_back(nums[idx]);
//                 cur /= 2;
//                 idx++;
//             }
//             res.push_back(tmp);
//             k--;
//         }
//         return res;
//     }
// };