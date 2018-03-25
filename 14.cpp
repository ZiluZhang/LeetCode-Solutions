class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0)
            return "";
        string pref = strs[0];
        for(int i = 1; i < len; i++)
        {
            int preflen = pref.length();
            int j;
            for(j = 0; j < preflen; j++)
                if(strs[i][j] != pref[j])
                    break;
            pref = pref.substr(0,j);
            if(pref.length() == 0)
                break;
        }
        return pref;
    }
};