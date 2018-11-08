// Course Schedule II
// 注意边的方向是pair.second --> pair.first
// 先修课 --> 课


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        queue<int> q;
        for(auto edge: prerequisites) {
            graph[edge.second].push_back(edge.first);
            in[edge.first]++;
        }
        for(int i = 0; i < numCourses; i++)
            if(in[i] == 0)
                q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for(auto tmp: graph[cur]) {
                if(--in[tmp] == 0)
                    q.push(tmp);
            }
        }
        for(int i = 0; i < numCourses; i++)
            if(in[i] != 0)
                return {};
        return res;
    }
};