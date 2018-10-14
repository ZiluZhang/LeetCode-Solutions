// Letter Combinations of a Phone Number
// string和char/string都可以直接相加
// 用copy(a.begin(),a.end(),b.begin())可以把a复制到b，但要保证b够大
// a.clear()可以清空自己
// 用a初始化b vector<T> b(a)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len == 0) return {};
        map<char, vector<string>> dic;
        dic.insert(pair<char, vector<string>>('2', {"a","b","c"}));
        dic.insert(pair<char, vector<string>>('3', {"d","e","f"}));
        dic.insert(pair<char, vector<string>>('4', {"g","h","i"}));
        dic.insert(pair<char, vector<string>>('5', {"j","k","l"}));
        dic.insert(pair<char, vector<string>>('6', {"m","n","o"}));
        dic.insert(pair<char, vector<string>>('7', {"p","q","r","s"}));
        dic.insert(pair<char, vector<string>>('8', {"t","u","v"}));
        dic.insert(pair<char, vector<string>>('9', {"w","x","y","z"}));
        vector<string> cur;
        // vector<string> prev;
        int cnt = dic[digits[0]].size();
        for(int k = 0; k < cnt; k++)
            cur.push_back(dic[digits[0]][k]);
        // for(int k = 0; k < cur.size(); k++)
        //     cout << cur[k] << endl;
        // up is corrent
        int prev_len = 0;
        for(int i = 1; i < len; i++) {
            vector<string> prev(cur);
            cur.clear();
            cnt = dic[digits[i]].size();
            prev_len = prev.size();
            for(int j = 0; j < prev_len; j++) {
                for(int k = 0; k < cnt; k++) {
                    cur.push_back(prev[j]+dic[digits[i]][k]);
                }
            }
        }
        return cur;
    }
};