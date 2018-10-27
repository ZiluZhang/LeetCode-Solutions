// Random Pick with Weight
// 权重累计，然后二分
// 注意边界

#include <cstdlib>
class Solution {
public:
    vector<int> wsum;
    Solution(vector<int> w) {
        int len = w.size();
        wsum.push_back(w[0]);
        for(int i = 1; i < len; i++)
            wsum.push_back(w[i] + wsum[i-1]);
    }
    
    int pickIndex() {
        int len = wsum.size();
        int num = rand() % (wsum[len-1]);
        int left = 0, right = len-1;
        // important!
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(wsum[mid] <= num) left = mid + 1;
            // important!
            else right = mid;
        }
        return right;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */