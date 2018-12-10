// Largest Palindrome Product
// 两个n位数相乘得到的结果，要求是回文数，求最大的这个回文数
// 除了n=1以外，其他情况最大回文数都是2n位的
// 
class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10,n)-1, lower = upper / 10;
        for(int i = upper; i > lower; i--) {
            string t = to_string(i);
            long cur = stol(t + string(t.rbegin(), t.rend()));
            for(long j = upper; j*j >= cur; j--) {
                if(cur % j == 0) return cur % 1337;
            }
        }
        return 9;
    }
};