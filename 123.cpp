// Best Time to Buy and Sell Stock  III



// O(n)
// 这个解法有点美妙啊
// 188是普通情况，k次，也可以这样解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for(int i = 0; i < len; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
    }
};


// dynamic programming
// l表示第j次必须在第i天的最优，g表示前j次在前i天完成的最优
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int res = 0;
        vector<vector<int>> l(len, vector<int>(3, 0));
        vector<vector<int>> g(len, vector<int>(3, 0));
        for(int i = 1; i < len; i++) {
            int benefit = prices[i] - prices[i-1];
            for(int j = 1; j <= 2; j++) {
                l[i][j] = max(g[i-1][j-1] + max(benefit,0), l[i-1][j]+benefit);
                g[i][j] = max(g[i-1][j], l[i][j]);
            }
        }
        return g[len-1][2];
    }
};