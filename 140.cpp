// Word Break II
// 递归，查某个字符串的所有拆分结果
// 用unordered_map存结果
// 对wordDict里面每个词，都看是否可以，如果可以，就拿到这个词后面子串的拆分结果，然后把这个词添进去



class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> umap;
        return getString(s, wordDict, umap);
    }
    
    vector<string> getString(string s, vector<string>& words, unordered_map<string, vector<string>>& umap) {
        if(!s.length()) return {""};
        if(umap.count(s)) return umap[s];
        vector<string> res;
        for(auto w: words) {
            if(s.substr(0, w.size()) != w) continue;
            vector<string> tmp = getString(s.substr(w.size()), words, umap);
            for(auto v: tmp) {
                res.push_back(w + (v.length() ? " " : "") + v);
            }
        }
        umap[s] = res;
        return res;
    }
};