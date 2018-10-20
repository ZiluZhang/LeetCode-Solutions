// Divide Two Integers
// INT_MAX这种在头文件limits.h
// 注意负界比正界大，所以做任何运算都先转成long
// 重要！(0-(long)dividend)必须转long，否则如果是INT_MIN就会越界
// 每一次把除数翻倍，省时
#include <limits.h>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool neg = (dividend < 0) != (divisor < 0);
        long tmp1 = dividend < 0 ? (0-(long)dividend): dividend;
        long tmp2 = divisor < 0 ? (0-(long)divisor): divisor;
        long res = tmpdivide(tmp1, tmp2);
        if(neg) res = 0-res;
        return res == (int)res ? res: INT_MAX;
    }
    
    long tmpdivide(long n1, long n2) {
        // assumption: n1 > 0 and n2 > 0
        if(n1 == 0) return 0;
        long tmpres = 0;
        if(n1 < n2) return tmpres;
        long dupdivide = n2;
        long times = 1;
        while(n1 >= dupdivide) {
            n1 -= dupdivide;
            tmpres += times;
            dupdivide += dupdivide;
            times += times;
        }
        return tmpres + tmpdivide(n1, n2);
    }
};