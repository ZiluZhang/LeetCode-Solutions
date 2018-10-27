// Largest Rectangle in Histogram
// 栈，增序
// 小于等于栈顶，就退栈，计算一下


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if(len == 0) return 0;
        int res = 0;
        stack<int> s;
        height.push_back(0);
        len = height.size();
        for(int i = 0; i < len; i++) {
            while(!s.empty() && height[s.top()] >= height[i]) {
                int cur = s.top();
                s.pop();
                res = max(res, height[cur] * (s.empty() ? i: (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};