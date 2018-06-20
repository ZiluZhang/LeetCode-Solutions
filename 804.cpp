class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string tmp[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // vector<string> dic(tmp, tmp+26);
        vector<string> res;
        int num = words.size();
        for(int i = 0; i < num; i++)
        {
            string w = words[i];
            string cur;
            int curlen = w.length();
            for(int j = 0; j < curlen; j++)
                cur += tmp[w[j]-'a'];
            if(find(res.begin(), res.end(), cur) == res.end())
                res.push_back(cur);
        }
        return res.size();
    }
};