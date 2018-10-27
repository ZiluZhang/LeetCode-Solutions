// Product of Array Except Self
// 正一遍反一遍
// 注意正一遍不能乘自己

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return {};
        vector<int> res(len, 1);
        res[0] = 1;
        for(int i = 1; i < len; i++)
            res[i] = res[i-1] * nums[i-1];
        int tmp = 1;
        for(int i = len-1; i >= 0; i--) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int len = nums.size();
//         vector<int> res(len, 1);
//         for(int i = 0; i < len; i++)
//         {
//             if(i == 0)
//                 res[i] = 1;
//             else
//                 res[i] = nums[i-1] * res[i-1];
//         }
//         // [1, a1, a1a2, a1a2a3]
//         // [a2a3a4, a3a4, a4, 1]
//         int tmp = 1;
//         for(int i = len-1; i >= 0; i--)
//         {
//             res[i] *= tmp;
//             tmp *= nums[i];
//         }
//         return res;
//     }
// };