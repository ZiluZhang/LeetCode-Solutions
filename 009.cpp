class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reversenum = 0;
        while(x > reversenum)
        {
            reversenum = reversenum * 10 + x % 10;
            x /= 10;
        }
        return (x == reversenum || x == reversenum / 10);
    }
};