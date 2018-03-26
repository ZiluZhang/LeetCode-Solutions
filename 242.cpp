class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if(len1 != len2)
            return false;
        vector<int> cnt1(26, 0);
        for(int i = 0; i < len1; i++)
        {
            cnt1[s[i]-'a']++;
            cnt1[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(cnt1[i] != 0)
                return false;
        return true;
    }
};