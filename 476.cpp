class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int mask = 1;
        while(num)
        {
            if(!(num & 1))
                res += mask;
            mask <<= 1;
            num >>= 1;
        }
        return res;
    }
};