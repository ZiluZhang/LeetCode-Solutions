// Frog Jump
// 给了哪些位置有石头，青蛙这次跳了k，下次只能跳k-1或k或k+1，能不能跳到最后一块石头

// DFS同时记录下来
// 如果想记录的东西key是二维的，如果用pair需要自己定义hash，所以可以用<int, map<int, xxx>>
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool>> dic;
        return helper(0, 0, stones, dic);
    }
    
    bool helper(int pos, int jump, vector<int>& stones, unordered_map<int, unordered_map<int, bool>>& dic) {
        int n = stones.size();
        if(pos >= n-1) return true;
        if(dic[pos].count(jump)) return dic[pos][jump];
        for(int i = pos+1; i < n; i++) {
            int dist = stones[i] - stones[pos];
            if(dist < jump - 1) continue;
            else if(dist > jump + 1) return dic[pos][jump] = false;
            else {
                if(helper(i, dist, stones, dic)) return dic[pos][jump] = true;
            }
        }
        return dic[pos][jump] = false;
    }
};


// dp
// dic记录的是，每个位置，可以到达这个位置的所有情况的最后一跳距离
// dp记录的是，到每个位置最后一跳距离中最大的值
// 所以如果这个位置能跳的最大距离+1都不能到另一个位置，就考虑下一个位置吧
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int num = stones.size();
        vector<int> dp(num, 0);
        unordered_map<int, unordered_set<int>> dic;
        dic[0].insert(0);
        int k = 0;
        for(int i = 1; i < num; i++) {
            while(dp[k] + 1 < stones[i] - stones[k]) k++;
            for(int j = k; j < i; j++) {
                int dist = stones[i] - stones[j];
                if(dic[j].count(dist) || dic[j].count(dist-1) || dic[j].count(dist+1)) {
                    dic[i].insert(dist);
                    dp[i] = max(dp[i], dist);
                }
            }
        }
        return dp[num-1] > 0;
    }
};