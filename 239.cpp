// Sliding Window Maximum
// deque双端队列，头尾都可以push/pop
// 我们要让deque里面存index，index递增，并且index里的值递减
// 如果头是i-k，说明头已经不在窗口里了，去掉

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return {};
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < len; i++) {
            if(!q.empty() && q.front() == i-k) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if(i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};