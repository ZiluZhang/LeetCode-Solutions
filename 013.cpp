// Roman to Integer
// 罗马数字，如果这个位置比后面位置小，就是减法，否则加法
// 记得加最后一位的数字
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        map<char, int> dic;
        dic.insert(pair<char, int>('M', 1000));
        dic.insert(pair<char, int>('D', 500));
        dic.insert(pair<char, int>('C', 100));
        dic.insert(pair<char, int>('L', 50));
        dic.insert(pair<char, int>('X', 10));
        dic.insert(pair<char, int>('V', 5));
        dic.insert(pair<char, int>('I', 1));
        vector<int> res;
        for(int i = 0; i < len; i++) {
            res.push_back(dic[s[i]]);
        }
        int num = 0;
        for(int i = 0; i < len-1; i++) {
            if(res[i] < res[i+1])
                num -= res[i];
            else
                num += res[i];
        }
        num += res[len-1];
        return num;
    }
};

// class Solution {
// public:
//     int romanToInt(string s) {
//         int len = s.length();
//         int num = 0;
//         for(int i = 0; i < len; i++)
//         {
//             switch(s[i]){
//                 case 'M':
//                     num += 1000;
//                     break;
//                 case 'D':
//                     num += 500;
//                     break;
//                 case 'C':
//                     if(i < len-1 && (s[i+1] == 'D' || s[i+1] == 'M'))
//                         num -= 100;
//                     else
//                         num += 100;
//                     break;
//                 case 'L':
//                     num += 50;
//                     break;
//                 case 'X':
//                     if(i < len-1 && (s[i+1] == 'L' || s[i+1] == 'C'))
//                         num -= 10;
//                     else
//                         num += 10;
//                     break;
//                 case 'V':
//                     num += 5;
//                     break;
//                 case 'I':
//                     if(i < len-1 && (s[i+1] == 'V' || s[i+1] == 'X'))
//                         num -= 1;
//                     else
//                         num += 1;
//                     break;
//                 default:
//                     break;
//             }
//         }
//         return num;
//     }
// };