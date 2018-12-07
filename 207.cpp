// Course Schedule
// 有向图里面有没有环

// BFS
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


// DFS
// 用0/-1/1标记visited
// 0表示没访问过
// -1表示当前这一轮访问过，那如果又遇到，就有环
// 1表示之前某轮访问过，再访问到也无所谓
// 所以访问到某个节点，先设为-1，然后深搜所有它指向的节点，访问完改为1
// 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for(auto edge: prerequisites) {
            graph[edge.first].push_back(edge.second);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!DFS(graph, visited, i)) return false;
        }
        return true;
    }
    
    bool DFS(vector<vector<int>>& graph, vector<int>& visited, int cur) {
        if(visited[cur] == -1) return false;
        if(visited[cur] == 1) return true;
        visited[cur] = -1;
        for(auto i : graph[cur]) {
            if(!DFS(graph, visited, i)) return false;
        }
        visited[cur] = 1;
        return true;
    }
};