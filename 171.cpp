class Solution {
public:
    int titleToNumber(string s) {
        long int num = 0;
        int len = s.length();
        long int mask = 1;
        // cout << s[0] - 'A' << endl;
        for(int i = len-1; i >= 0; i--)
        {
            num += mask * (s[i] - 'A' + 1);
            mask *= 26;
        }
        return num;
    }
};