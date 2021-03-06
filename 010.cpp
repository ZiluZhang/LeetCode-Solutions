// Regular Expression Matching
// 如果p[1]不是'*'，第一位要严格匹配，再匹配后面部分
// 如果p[1]是'*'，因为可以0次，所以要么不管它，要么一位一位匹配
// 

// recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length()==1) return s.length()==1 && (s[0]==p[0] || p[0]=='.');
        if(p[1] != '*') {
            if(s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if(isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};


// dynamic programming
// P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
// P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
// P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(j > 1 && p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2]
                        || (i > 0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                } else {
                    dp[i][j] = i > 0
                        && dp[i-1][j-1]
                        && (s[i-1]==p[j-1] || p[j-1]=='.');
                }
            }
        }
        return dp[m][n];
    }
};