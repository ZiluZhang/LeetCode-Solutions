// Alien Dictionary
// 找出新的字典序
// 对于每两个相邻的单词，能得出字典序的是，第一个出现的不同的char
// 把所有字母放在一个unordered_set里，把所有字典序pair放在另一个set里，同时计算入度
// 用queue每次把入度为0的加上
// 最后如果子串长度=字母个数，就对了

/*
set不是hash，unordered_set是hash，所以用pair的时候要自己定义hash操作
https://coherence0815.wordpress.com/2016/10/13/use-unordered_set-in-c-11/
struct MyHash {
    size_t operator()(const pair<int, int> & v) const {
        return v.first ^ v.second;
    }
};
unordered_set <pair<int, int>, MyHash> myset;
*/

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