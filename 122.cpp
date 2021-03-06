// Best Time to Buy and Sell Stock  II
// 遍历一次就行！
// 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int res = 0;
        for(int i = 0; i < len-1; i++) {
            if(prices[i+1] > prices[i]) //非常巧妙！
                res += prices[i+1] - prices[i];
        }
        return res;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if(len <= 1)
//             return 0;
//         int maxprofit = 0;
//         int high = prices[0];
//         int low = prices[0];
//         int i = 1;
//         while(i < len)
//         {
//             while(i < len && prices[i] <= low)
//             {
//                 low = prices[i];
//                 i++;
//             }
//             high = low;
//             cout << low << high << i << endl;
//             while(i < len && prices[i] >= high)
//             {
//                 high = prices[i];
//                 i++;
//             }
//             cout << low << high << i << endl;
//             maxprofit += high - low;
//             // i++;
//             low = high = prices[i];
//         }
//         return maxprofit;
//     }
// };