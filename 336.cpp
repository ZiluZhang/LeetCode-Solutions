// Palindrome Pairs
// 每一对string，是否能连接成回文串。考虑左右排列

// 暴力搜会超时
// 用unorder_map记录每个串的index
// 对于每一个串的每一个位置[0,len]
    //判断如果左边部分是回文并且右边的reverse之后存在，就加入
    //如果右边......
        // 注意位置不是len的时候再进入，否则会有重复

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int num = words.size();
        unordered_map<string, int> dic;
        vector<vector<int>> res;
        for(int i = 0; i < num; i++) {
            dic[words[i]] = i;
        }
        for(int i = 0; i < num; i++) {
            string cur = words[i];
            string cur_r = cur;
            reverse(cur_r.begin(), cur_r.end());
            int len = cur.length();
            for(int j = 0; j <= len; j++) {
                if(isPalindrome(cur.substr(0,j))) {
                    if(dic.find(cur_r.substr(0, len-j)) != dic.end()) {
                        if(dic[cur_r.substr(0, len-j)] != i) {
                            res.push_back({dic[cur_r.substr(0, len-j)], i});
                        }
                    }
                }
                // 这里j!=len是为了防止重复！！！
                if(j != len && isPalindrome(cur.substr(j))) {
                    if(dic.find(cur_r.substr(len-j)) != dic.end()) {
                        if(dic[cur_r.substr(len-j)] != i) {
                            res.push_back({i, dic[cur_r.substr(len-j)]});
                        }
                    }
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        int len = s.length();
        for(int i = 0; i < len/2; i++) {
            if(s[i] != s[len-1-i]) return false;
        }
        return true;
    }
};