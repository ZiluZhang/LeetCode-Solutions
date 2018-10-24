// Minimum Window Substring
// 左右指针，里面是子串
// 用vector记录每一种character出现的次数
// 如果每一种都不少于target中次数，就是满足要求的
// 如果满足要求，左指针右移，更新vector
// 如果不满足要求，右指针右移，更新vector

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len2 > len1) return "";
        vector<int> cnt(288, 0);
        vector<int> chk(288, 0);
        for(int k = 0; k < len2; k++)
            chk[t[k]] ++;
        int i = 0, j = 0;
        string res;
        int min_len = -1;
        bool suc = false;
        cnt[s[0]]++;
        while(i + len2 <= len1 && j < len1) {
            if(j-i+1 < len2) {
                cnt[s[++j]]++;
                continue;
            }
            suc = true;
            for(int k = 0; k < 288; k++) {
                if(cnt[k] < chk[k]) {
                    suc = false;
                    j++;
                    if(j < len1)
                        cnt[s[j]] ++;
                    break;
                }
            }
            if(suc) {
                if(min_len == -1 || min_len > (j - i + 1)) {
                    min_len = j - i + 1;
                    res = s.substr(i, j-i+1);
                }
                cnt[s[i++]]--;
            }
        }
        return res;
    }
};