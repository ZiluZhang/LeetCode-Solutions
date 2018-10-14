// Longest Palindromic Substring
// 回文，用动态规划
// 窗口为1扫一轮，窗口为2扫一轮，……
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<bool> tmp(len, false);
        vector<vector<bool>> dic(len, tmp);
        int maxbegin = 0;
        int maxlen = 0;
        for(int i = 0; i < len; i++)
            dic[i][i] = true;
        for(int k = 1; k < len; k++) {
            for(int i = 0; i < len-k; i++) {
                if(s[i] == s[i+k]) {
                    if(k == 1) {
                        dic[i][i+k] = true;
                        maxbegin = k > maxlen ? i: maxbegin;
                        maxlen = k > maxlen ? k: maxlen;
                    }
                    else if(dic[i+1][i+k-1]) {
                        dic[i][i+k] = true;
                        maxbegin = k > maxlen ? i: maxbegin;
                        maxlen = k > maxlen ? k: maxlen;                        
                    }
                }
            }
        }
        return s.substr(maxbegin, maxlen+1);
    }
};