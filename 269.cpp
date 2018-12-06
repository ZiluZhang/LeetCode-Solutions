// Alien Dictionary
// 
// 

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int num = words.size();
        unordered_set<char> chars;
        set<pair<char, char>> s;
        vector<int> in(256,0);
        for(auto w: words)
            chars.insert(w.begin(), w.end());
        for(int i = 0; i < num-1; i++) {
            int min_len = min(words[i].length(), words[i+1].length());
            for(int j = 0; j < min_len; j++) {
                if(words[i][j] != words[i+1][j]) {
                    s.insert(pair<char,char>(words[i][j], words[i+1][j]));
                    // cout << words[i][j] << ' ' << words[i+1][j] << endl;
                    break;
                }
            }
        }
        // 不在insert的时候算，怕有重复，set可以去重
        for(auto a:s) {
            in[a.second]++;
        }
        queue<char> q;
        string res;
        for(auto i:chars) {
            if(in[i] == 0) {
                q.push(i);
                res += i;
            }
        }
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            for(auto a:s) {
                if(a.first == c) {
                    in[a.second]--;
                    if(in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        // cout << res << endl;
        return res.length() == chars.size() ? res : "";
    }
};