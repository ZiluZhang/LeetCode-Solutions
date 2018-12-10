// Parse Lisp Expression
// 
// 
// 
class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> m;
        return helper(expression, m);
    }
    
    //处理每一个式子，返回时式子的值
    int helper(string str, unordered_map<string, int> m) {
        if(str[0] == '-' || (str[0] >= '0' && str[0] <= '9')) return stoi(str); // it is an integer
        else if(str[0] != '(') return m[str]; // it is a variable
        string s = str.substr(1, str.size() - 2); // remove outer parentheses
        int cur = 0;
        string cmd = parse(s, cur);
        if(cmd == "let") {
            while(true) {
                string var = parse(s, cur);
                if(cur > s.size()) return helper(var, m);
                string t = parse(s, cur);
                m[var] = helper(t, m);
            }
        } else if(cmd == "add") {
            return helper(parse(s, cur), m) + helper(parse(s, cur), m);
        } else if(cmd == "mult") {
            return helper(parse(s, cur), m) * helper(parse(s, cur), m);
        }
    }

    // 这个函数做的事
    // 把s中的第一部分拿出来，并且把cur改为指向下一部分
    // 部分：可能是一个cmd，也可能cmd之后的某一个式子
    // 这个部分可能是通过空格拿到的，也可能是通过括号括起来的
    // 这里要修改cur值，所以用&
    string parse(string s, int& cur ) {
        int j = cur + 1;
        int prev = cur;
        if(s[cur] == '(') {
            int cnt = 1;
            while(cnt != 0) {
                if(s[j] == '(') cnt++;
                else if(s[j] == ')') cnt--;
                j++;
            }
        }
        else {
            while(j < s.length() && s[j] != ' ') j++;
        }
        cur = j+1;
        return s.substr(prev, j-prev); // return the cmd
    }
};