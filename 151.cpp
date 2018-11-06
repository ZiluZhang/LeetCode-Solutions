// Reverse Words in a String
// 先把字符串翻转，再把每个单词翻转
// 用cur记录结果字串记录到哪，用i记录原字串记录到哪
// 判断是否要查空格，就是看结果字串是不是在最开始
// reverse(mystring.begin(), mystring.end())

class Solution {
public:
    void reverseWords(string &s) {
        int cur = 0;
        int len = s.length();
        reverse(s.begin(), s.end());
        for(int i = 0; i < len; i++) {
            if(s[i] != ' ') {
                if(cur != 0) s[cur++] = ' ';
                int j = i;
                while(j < len && s[j] != ' ') s[cur++] = s[j++];
                reverse(s.begin() + cur - (j-i), s.begin() + cur);
                i = j;
            }
        }
        s = s.substr(0,cur);
        return;
    }
};