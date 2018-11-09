// Basic Calculator III
// 加减乘除，括号


class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        int num = 0;
        int curRes = 0;
        int res = 0;
        char op = '+';
        for(int i = 0; i < len; i++) {
            if(s[i] >= '0') {
                num = num * 10 + s[i]-'0';
            }
            else if(s[i] == '(') {
                int cnt = 0;
                int j = i;
                while(i < len) {
                    if(s[i] == '(') cnt++;
                    if(s[i] == ')') cnt--;
                    if(cnt == 0) break;
                    i++;
                }
                num = calculate(s.substr(j+1, i-j-1));
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == len-1) {
                switch(op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if(s[i] == '+' || s[i] == '-' || i == len-1) {
                    res += curRes;
                    curRes = 0;
                }
                op = s[i];
                num = 0;
            }
        }
        return res;
    }
};