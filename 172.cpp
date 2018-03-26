class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
            return 0;
        long int cnt = 0;
        long int mask = 5;
        while(n >= mask)
        {
            cnt += n / mask;
            mask *= 5;
        }
        return cnt;
    }
};