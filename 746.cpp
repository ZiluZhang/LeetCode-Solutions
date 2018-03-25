class Solution {
public:
    // vector<int> c;
    // int len;
    // int findcost(int idx)
    // {
    //     if(idx >= len)
    //         return 0;
    //     return c[idx] + min(findcost())
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        // c = cost;
        // len = cost.size();
        int len = cost.size();
        vector<int> tmp(len, 0);
        for(int i = len-1; i >= 0; i--)
        {
            if(i == len-1 || i == len-2)
                tmp[i] = cost[i];
            else
                tmp[i] = cost[i] + min(tmp[i+1], tmp[i+2]);
        }
        return min(tmp[0], tmp[1]);
    }
};