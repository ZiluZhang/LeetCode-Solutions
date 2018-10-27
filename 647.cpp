// Palindromic Substrings
// 每一个位置当做中间位置，往两边，如果相等就++
// 注意函数参数是int &型，传参的时候还是myint


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            checkPalindromic(s, res, i, i, len);
            checkPalindromic(s, res, i, i+1, len);
        }
        return res;
    }
    
    void checkPalindromic(string s, int & res, int i, int j, int len) {
        while(i >= 0 && j < len && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return;
    }
};