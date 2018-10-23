// Best Time to Buy and Sell Stock
// 如果比当前buy大，更新结果
// 如果比当前buy小，更新buy

#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int res = 0;
        int buy = prices[0];
        for(int i = 1; i < len; i++) {
            res = max(res, prices[i] - buy);
            buy = min(prices[i], buy);
        }
        return res;
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if(len == 0)
//             return 0;
//         int minimum = prices[0];
//         int maxprofit = 0;
//         for(int i = 1; i < len; i++)
//         {
//             if(prices[i] < minimum)
//                 minimum = prices[i];
//             if(maxprofit < prices[i] - minimum)
//                 maxprofit = prices[i] - minimum;
//         }
//         return maxprofit;
//     }
// };