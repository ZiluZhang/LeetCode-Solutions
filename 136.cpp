// Single Number
// 异或，相同的异或为0，某个数和0异或还是自己
// 所以把所有数异或起来，剩的那个就是single number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for(int i = 0; i < len; i++)
            res ^= nums[i];
        return res;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int len = nums.size();
//         int a = 0;
//         for(int i = 0; i < len; i++)
//             a ^= nums[i];
//         return a;
//     }
// };