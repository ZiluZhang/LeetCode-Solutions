// Basic Calculator II
// 有乘除法了，没有括号
// op记录前一个运算符
// 每次遇到运算符或者到达结尾，就计算一下
// 如果是加减法，就先放到栈里，不计算结果
// 如果乘除法，和栈顶计算一下
// 最后把栈里元素都加起来

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        stack<int> st;
        int num = 0;
        char op = '+';
        for(int i = 0; i < len; i++) {
            if(s[i] >= '0') {
                num = num * 10 + s[i]-'0';
            }
            if((s[i] < '0' && s[i] != ' ') || i == len-1) {
                if(op == '+') st.push(num);
                else if(op == '-') st.push(-num);
                else if(op == '*') {
                    int tmp = st.top() * num;
                    st.pop();
                    st.push(tmp);
                }
                else if(op == '/') {
                    int tmp = st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};