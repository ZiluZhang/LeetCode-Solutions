// Course Schedule
// 有向图里面有没有环
// 记录每个点的入度
// 用queue维护当前入度为0的点，每次把从这个点出去的所有边删掉，如果有新的入度为0的点就加进去
// 最后，如果还有点入度不为0，说明有环

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for(auto pre: prerequisites) {
            graph[pre.first].push_back(pre.second);
            in[pre.second]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(in[i] == 0)
                q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(auto tmp: graph[cur]) {
                // in[tmp]--;
                if(--in[tmp] == 0)
                    q.push(tmp);
            }
        }
        for(int i = 0; i < numCourses; i++)
            if(in[i] != 0)
                return false;
        return true;
    }
};