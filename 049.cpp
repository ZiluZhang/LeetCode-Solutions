// Group Anagrams
// string可以sort！
// map的iterator是指针，first是key，second是value
// map如果没有这个key，可以自动创建

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        map<string, vector<string>> dic;
        vector<vector<string>> res;
        for(int i = 0; i < len; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            dic[tmp].push_back(strs[i]);
        }
        for(auto it = dic.begin(); it != dic.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};