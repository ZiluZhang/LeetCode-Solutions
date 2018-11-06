// One Edit Distance
// 编辑距离是否为1
// 遇到不等的，根据两个子串长度分类

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        for(int i = 0; i < min(len1, len2); i++) {
            if(s[i] != t[i]) {
                if(len1 == len2) return s.substr(i+1) == t.substr(i+1);
                else if(len1 < len2) return s.substr(i) == t.substr(i+1);
                else return s.substr(i+1) == t.substr(i);
            }
        }
        return abs(len1-len2) == 1;
    }
};