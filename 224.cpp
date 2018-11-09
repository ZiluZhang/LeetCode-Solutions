// Basic Calculator
// 因为有括号，所以用栈
// 遇到数字，就求出完整数字
// 遇到符号，更新sign，其中1表示加，-1表示减，初始默认加
// 遇到左括号，推栈，把当前结果、符号推栈
// 遇到右括号，从栈取出之前的结果、符号

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0;
        int sign = 1; // +: 1; -: -1
        int len = s.length();
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if('0'<= c && c <= '9') {
                int num = 0;
                while(i < len && '0' <= s[i] && s[i] <= '9') {
                    num = num * 10 + s[i++]-'0';
                }
                res += sign * num;
                i--;
            } else if(c == '+') {
                sign = 1;
            } else if(c == '-') {
                sign = -1;
            } else if(c == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            } else if(c == ')') {
                int tmpsign = st.top(); st.pop();
                int tmpres = st.top(); st.pop();
                res = res * tmpsign + tmpres;
            }
        }
        return res;
    }
};