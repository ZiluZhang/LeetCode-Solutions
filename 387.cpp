// First Unique Character in a String
// 
// 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            cnt[s[i]] ++;
        }
        for(int i = 0; i < len; i++) {
            if(cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};