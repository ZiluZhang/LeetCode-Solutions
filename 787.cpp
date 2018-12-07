// Cheapest Flights Within K Stops
// 存有向图，可以用unordered_map<int, vector<int>>，不用初始化

// DFS用helper函数
// visited记录有没有访问过
// 如果cur就是目的地，到了！更新res
// 对每一个边遍历，如果访问过或者已经不如当前最优，剪枝
// 先设为访问过，然后深搜这个点，回来之后改为没访问
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<vector<int>>> m;
        vector<bool> visited(n, false);
        visited[src] = true;;
        for(auto f:flights) {
            m[f[0]].push_back({f[1], f[2]});
        }
        int res = INT_MAX;
        helper(m, src, dst, K, visited, 0, res);
        return (res == INT_MAX) ? -1 : res;
    }
    
    void helper(unordered_map<int, vector<vector<int>>>& m, int cur, int dst, int K, vector<bool>& visited, int out, int& res) {
        if(cur == dst) {
            res = out;
            return;
        }
        if(K < 0) return;
        for(auto f:m[cur]) {
            if(visited[f[0]] || out + f[1] > res)
                continue;
            visited[f[0]] = true;
            helper(m, f[0], dst, K-1, visited, out+f[1], res);
            visited[f[0]] = false;
        }
    }
};


// BFS用queue
// 至多K次
// queue中存的是，到达的位置，和当前花了多少钱
// 如果到达位置刚好是目的地，更新res
// 如果当前花的钱已经超过了最优，剪枝
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = INT_MAX;
        int cnt = 0;
        unordered_map<int, vector<vector<int>>> m;
        queue<vector<int>> q;
        q.push({src, 0});
        for(auto f:flights) {
            m[f[0]].push_back({f[1], f[2]});
        }
        while(!q.empty()) {
            for(int k = q.size(); k > 0; k--) {
                auto t = q.front(); q.pop();
                if(t[0] == dst) res = min(res, t[1]);
                for(auto f:m[t[0]]) {
                    if(t[1] + f[1] > res) continue;
                    q.push({f[0], t[1]+f[1]});
                }
            }
            if(cnt++ > K)
                break;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};


// DP
// dp[i][j]表示至多i次之后，到j的最小价格
// dp[i][f[1]] = min(dp[i][f[1]], dp[i-1][f[0]] + f[2])
// 一般dp都是min(dp[i-1][j], dp[i-1][k] + (k->j))但是这个没有
// 因为每一轮最开始都设了dp[0][src]=0！！！！！我懂了！
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K+2, vector<int>(n, 1e7));
        dp[0][src] = 0;
        for(int i = 1; i <= K+1; i++) {
            dp[i][src] = 0;
            for(auto f:flights) {
                dp[i][f[1]] = min(dp[i][f[1]], dp[i-1][f[0]] + f[2]);
            }
        }
        cout << dp[K+1][dst] << endl;
        return dp[K+1][dst] == 1e7 ? -1 : dp[K+1][dst];
    }
};