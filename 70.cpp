class Solution {
public:
    int climbStairs(int n) {
        vector<int> tmp(n, -1);
        tmp[0] = 1;
        tmp[1] = 2;
        for(int i = 2; i < n; i++)
        {
            tmp[i] = tmp[i-1] + tmp[i-2];
        }
        return tmp[n-1];
    }
};