// Plus One
// 更新当前位置的数可能会影响之后算进位，所以要用一个变量存一下
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(len == 0) return {1};
        digits[len-1] += 1;
        int s = digits[len-1] / 10;
        digits[len-1] %= 10;
        int tmp = 0;
        for(int i = len-2; i >= 0; i--) {
            tmp = digits[i] + s;
            digits[i] = tmp % 10;
            s = tmp / 10;
        }
        if(s > 0) {
            digits.insert(digits.begin(), s);
        }
        return digits;
    }
};

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         // digits[0] = digits[0] + 1;
//         // if(digits[0] == 10)
//         // {
//         //     digits[0] = 1;
//         //     digits.push_back(0);
//         // }
//         int len = digits.size();
//         // for(int i = 0; i < len; i++)
//         //     digits[i] += 1;
//         digits[len-1] += 1;
//         int addone = 0;
//         for(int j = len-1; j >= 0; j--)
//         {
//             int thisdigit = digits[j] + addone;
//             addone = thisdigit / 10;
//             digits[j] = thisdigit % 10;
//         }
//         if(addone > 0)
//             digits.insert(digits.begin(), addone);
//         return digits;
//     }
// };