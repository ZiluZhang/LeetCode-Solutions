class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len2 == 0)
            return 0;
        if(len1 == 0)
            return -1;
        for(int i = 0; i < len1; i++)
        {
            if(i+len2 > len1)
                break;
            if(needle.compare(haystack.substr(i,len2)) == 0)
                return i;
        }
        cout << needle.compare(haystack.substr(2,2+len2)) << endl;
        cout << needle << endl;
        cout << haystack.substr(2,2+len2) << endl;
        return -1;
    }
};