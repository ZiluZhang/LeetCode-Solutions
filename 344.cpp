class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        for(int i = 0; i < len/2; i++)
        {
            char tmp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = tmp;
        }
        return s;
    }
};