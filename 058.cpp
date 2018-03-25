class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int lastlen = 0;
        int cnt = 0;
        int j = len-1;
        while(s[j] == ' ')
            j--;
        for(int i = 0; i <= j; i++)
        {
            if(s[i] == ' ')
            {
                lastlen = cnt;
                cnt = 0;
            }
            else
                cnt++;
        }
        cout << cnt << endl;
        lastlen = cnt;
        return lastlen;
    }
};