class Solution {
public:
    int arrangeCoins(int n) {
        // k*(k+1)/2
        // k*(k+1)<=2*n<(k+1)*(k+2);
        if(n <= 1)
            return n;
        int tmp = sqrt(n)*3/2;
        for(int i = 1; i <= tmp; i++)
        {
            if(i*(i+1) <= 2*n && 2*n < (i+1)*(i+2))
                return i;
        }
        return n;
    }
};