// Word Break
// 用记忆数组递归，或动态规划
// [0,i)子串 = [0,j)子串 + [j,i)单词


// dynamic programming
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && words.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> suc(len, -1);
        return checkStart(s, words, 0, suc);
    }
    
    bool checkStart(string s, unordered_set<string>& words, int start, vector<int>& suc) {
        if(start >= s.length()) return true;
        if(suc[start] != -1) return suc[start];
        for(int i = start+1; i <= s.length(); i++) {
            if(words.count(s.substr(start, i-start)) > 0 && checkStart(s, words, i, suc)) {
                suc[start] = 1;
                return true;
            }
        }
        suc[start] = 0;
        return false;
    }
};