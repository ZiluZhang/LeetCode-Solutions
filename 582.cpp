// Kill Process
// 进程中的父子关系，树结构，kill了父进程的话子进程也被kill，问kill某个进城后都哪些被kill


// 相当于BFS
// 首先记录下每个进程有哪些儿子
// 每kill一个，就把儿子们加进去
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        vector<int> res;
        int num = pid.size();
        for(int i = 0; i < num; i++) {
            children[ppid[i]].push_back(pid[i]);
        }
        queue<int> q;
        q.push(kill);
        res.push_back(kill);
        while(!q.empty()) {
            int tmp = q.front(); q.pop();
            for(auto c:children[tmp]) {
                res.push_back(c);
                q.push(c);
            }
        }
        return res;
    }
};