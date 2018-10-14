// Longest Substring Without Repeating Characters
// 贪心法，扫一遍
// 如果遇到之前遇过的，更新dic
// 如果之前遇过的恰好在窗口里，更新窗口begin index
// 记得循环结束后也要更新结果
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dic;
        int len = s.length();
        if(len == 0)
            return 0;
        if(len == 1)
            return 1;
        int begin = 0;
        int maxlen = 1;
        dic.insert(pair<char,int>(s[begin], begin));
        for(int i = 1; i < len; i++) {
            if(begin >= len)
                break;
            if(i <= begin)
                continue;
            if(dic.find(s[i]) != dic.end()) {
                if(dic[s[i]] >= begin) {
                    maxlen = (i-begin) > maxlen? (i-begin):maxlen;
                    begin = dic[s[i]] + 1;
                }                
                dic[s[i]] = i;
            }
            else
                dic.insert(pair<char, int>(s[i], i));
        }
        // cout << len << " " << begin << endl;
        maxlen = (len-begin) > maxlen ? (len-begin):maxlen;
        return maxlen;
    }
};