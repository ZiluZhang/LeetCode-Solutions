// Decode Ways
// 纯考细节啊我的妈

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s[0] == '0') return 0;
        // if(len == 1) return 1;
        vector<int> num(len, 1);
        for(int i = 1; i < len; i++) {
            if(s[i] == '0') {
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                else if(i-2 >= 0) num[i] = num[i-2];
                else num[i] = 1;
                continue;
            }
            
            if(s[i-1] == '1') {
                if(i-2 >= 0) num[i] = num[i-1] + num[i-2];
                else num[i] = num[i-1] + 1;
            }
            else if(s[i-1] == '2') {
                if(s[i] >= '7') num[i] = num[i-1];
                else if(i-2 >= 0) num[i] = num[i-1] + num[i-2];
                else num[i] = num[i-1] + 1;
            }
            else {
                num[i] = num[i-1];
            }
        }
        return num[len-1];
    }
};