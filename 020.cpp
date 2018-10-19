// Valid Parentheses
// 左半边应该推栈，右半边应该和栈顶匹配
// 一定要判断栈非空！！！！！
// 最后也要判断栈非空
// mymap.find()用来找key，返回iterator
class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        int len = s.length();
        if(len == 0) return true;
        map<char, char> dic;
        dic.insert(pair<char, char>('(',')'));
        dic.insert(pair<char, char>('[',']'));
        dic.insert(pair<char, char>('{','}'));
        for(int i = 0; i < len; i++) {
            if(dic.find(s[i]) != dic.end()) {
                tmp.push(s[i]);
            }
            else {
                if(tmp.empty()) return false;
                char cur = tmp.top();
                if(s[i] != dic[cur])
                    return false;
                else
                    tmp.pop();
            }
        }
        if(!tmp.empty()) return false;
        return true;
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//         int len = s.length();
//         stack<char> tmp;
//         bool res = true;
//         for(int i = 0; i < len; i++)
//         {
//             if(!res)
//                 return res;
//             switch(s[i]){
//                 case '(':
//                     tmp.push(s[i]);
//                     break;
//                 case '[':
//                     tmp.push(s[i]);
//                     break;
//                 case '{':
//                     tmp.push(s[i]);
//                     break;
//                 case ')':
//                     if(tmp.empty() || tmp.top() != '(')
//                         res = false;
//                     else
//                         tmp.pop();
//                     break;
//                 case ']':
//                     if(tmp.empty() || tmp.top() != '[')
//                         res = false;
//                     else
//                         tmp.pop();
//                     break;
//                 case '}':
//                     if(tmp.empty() || tmp.top() != '{')
//                         res = false;
//                     else
//                         tmp.pop();
//                     break;
//             }
//         }
//         if(!tmp.empty())
//             return false;
//         return res;
//     }
// };