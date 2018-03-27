class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        vector<int> idx;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
              || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                idx.push_back(i);
            }
        }
        int cnt = idx.size();
        for(int i = 0; i < cnt/2; i++)
        {
            char tmp = s[idx[i]];
            s[idx[i]] = s[idx[cnt-1-i]];
            s[idx[cnt-1-i]] = tmp;
        }
        return s;
    }
};