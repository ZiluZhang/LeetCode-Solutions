class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> tmp;
        bool res = true;
        for(int i = 0; i < len; i++)
        {
            if(!res)
                return res;
            switch(s[i]){
                case '(':
                    tmp.push(s[i]);
                    break;
                case '[':
                    tmp.push(s[i]);
                    break;
                case '{':
                    tmp.push(s[i]);
                    break;
                case ')':
                    if(tmp.empty() || tmp.top() != '(')
                        res = false;
                    else
                        tmp.pop();
                    break;
                case ']':
                    if(tmp.empty() || tmp.top() != '[')
                        res = false;
                    else
                        tmp.pop();
                    break;
                case '}':
                    if(tmp.empty() || tmp.top() != '{')
                        res = false;
                    else
                        tmp.pop();
                    break;
            }
        }
        if(!tmp.empty())
            return false;
        return res;
    }
};