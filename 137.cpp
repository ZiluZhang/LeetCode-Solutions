// Single Number II
// 对每一位，记录所有数在这一位上1的个数，模3就是single number在这一位上1的个数

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        for(int i = 0; i < 32; i++) {
            int tmp = 0;
            for(int j = 0; j < len; j++) {
                tmp += (nums[j] >> i) & 1;
            }
            res |= (tmp % 3) << i;
        }
        return res;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         vector<int> digs(32,0);
//         int len = nums.size();
//         for(int i = 0; i < len; i++)
//         {
//             int cur = nums[i];
//             for(int k = 0; k < 32; k++)
//             {
//                 digs[k] += cur & 1;
//                 cur >>= 1;
//                 if(!cur)
//                     break;
//             }
//         }
//         int res = 0;
//         for(int k = 0; k < 32; k++)
//         {
//             if((digs[k] % 3))
//                 res += 1 << k;
//         }
//         return res;
//     }
// };