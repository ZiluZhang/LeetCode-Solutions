// Remove Invalid Parentheses
// BFS，每一个位置都遍历
// 判断是否valid用cnt
// unordered_set可以查重，find/count都行，都是平均O(1)最坏O(n)
// unordered_map也可以，find/count也都平均O(1)最坏O(n)
// mystring.substr(i)表示从i开始到结尾的子串


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        vector<string> res;
        unordered_set<string> hash;
        q.push(s);
        hash.insert(s);
        while(!q.empty()) {
            int num = q.size();
            for(int i = 0; i < num; i++) {
                string cur = q.front(); q.pop();
                if(isValid(cur)) {
                    res.push_back(cur); continue;
                }
                int len = cur.length();
                for(int i = 0; i < len; i++) {
                    if (cur[i] != '(' && cur[i] != ')') continue;
                    string nxt = cur.substr(0,i)+cur.substr(i+1);
                    if(!hash.count(nxt)) {
                        hash.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            if(res.size()) break;
        }
        return res;
    }
    
    bool isValid(string s) {
        int len = s.length();
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt==0;
    }
};