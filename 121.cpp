class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int minimum = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < len; i++)
        {
            if(prices[i] < minimum)
                minimum = prices[i];
            if(maxprofit < prices[i] - minimum)
                maxprofit = prices[i] - minimum;
        }
        return maxprofit;
    }
};