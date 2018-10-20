// Pow(x, n)
// 二分，每次n/2
// 最先处理n负数情况
// 若n奇数，要再乘一次
// 终点是n=0

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return 1.0 / tmpPow(x, 0-n);
        else return tmpPow(x, n);
    }
    
    double tmpPow(double x, int n) {
        if(n == 0) return 1;
        double tmp = tmpPow(x, n/2);
        if(n % 2 == 0) return tmp * tmp;
        else return tmp * tmp * x;
    }
};