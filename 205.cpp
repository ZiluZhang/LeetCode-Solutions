class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> dic;
        vector<char> taken;
        vector<char> maped;
        int len1 = s.length();
        int len2 = t.length();
        if(len1 != len2)
            return false;
        for(int i = 0; i < len1; i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            if(find(maped.begin(), maped.end(), c1) != maped.end())
            {
                if(dic[c1] != c2)
                    return false;
            }
            else
            {
                if(find(taken.begin(), taken.end(), c2) != taken.end())
                    return false;
                else
                {
                    dic.insert(pair<char, char>(c1, c2));
                    taken.push_back(c2);
                    maped.push_back(c1);
                }
            }
        }
        return true;
    }
};