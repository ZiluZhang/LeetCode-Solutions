// Longest Common Prefix
// 共同前缀，以第一个为基准就可以
// 注意提前终止
// 取子串 substr(start_index, length)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0)
            return "";
        string pref = strs[0];
        for(int i = 1; i < len; i++) {
            int preflen = pref.length();
            for(int j = 0; j < preflen; j++) {
                if(strs[i][j] != pref[j]) {
                    pref = pref.substr(0, j);
                    break;
                }
            }
            if(pref.length() == 0)
                break;
        }
        return pref;
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int len = strs.size();
//         if(len == 0)
//             return "";
//         string pref = strs[0];
//         for(int i = 1; i < len; i++)
//         {
//             int preflen = pref.length();
//             int j;
//             for(j = 0; j < preflen; j++)
//                 if(strs[i][j] != pref[j])
//                     break;
//             pref = pref.substr(0,j);
//             if(pref.length() == 0)
//                 break;
//         }
//         return pref;
//     }
// };