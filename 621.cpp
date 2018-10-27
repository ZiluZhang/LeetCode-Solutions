// Task Scheduler
// 先排最多的，就能定下来至少有多少段n+1
// 最终结果不能小于task个数


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if(len <= 1) return len;
        vector<int> cnt(26, 0);
        for(int i = 0; i < len; i++)
            cnt[tasks[i]-'A']++;
        sort(cnt.begin(), cnt.end());
        int mx = cnt[25];
        int i = 25;
        while(i >= 0 && cnt[i] == mx)
            i--;
        return max(len, (mx-1)*(n+1)+25-i);
    }
};