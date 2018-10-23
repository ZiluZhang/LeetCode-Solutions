// Valid Palindrome
// isalnum(char)
// isalpha    isdigit
// tolower    toupper
// 


class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int i = 0;
        int j = len-1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i]))
                i++;
            while(i < j && !isalnum(s[j]))
                j--;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};