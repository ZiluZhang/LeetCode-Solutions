// two sum
// 看清题目，返回结果是index不是数字
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        if(len == 0)
            return res;
        for(int i = 0; i < len; i++) {
            for(int j = i+1; j < len; j++) {
                if(nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i1 = 0, i2 = 0;
//         bool found = false;
//         int len = nums.size();
//         int a, b;
//         for(int i = 0; i < len; i++)
//         {
//             if(found)
//                 break;
//             a = nums[i];
//             b = target - a;
//             for(int j = 0; j < len; j++)
//             {
//                 if(b == nums[j] && i != j)
//                 {
//                     found = true;
//                     i1 = i;
//                     i2 = j;
//                     break;
//                 }
//             }
//         }
//         vector<int> ans = vector<int>(2);
//         ans[0] = i1;
//         ans[1] = i2;
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         int len = nums.size();
//         if(len == 0)
//             return res;
//         for(int i = 0; i < len; i++)
//         {
//             for(int j = i+1; j < len; j++)
//             {
//                 if(nums[i] + nums[j] == target)
//                 {
//                     res.push_back(i);
//                     res.push_back(j);
//                     return res;
//                 }
//             }
//         }
//         return res;
//     }
// };