class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t cnt = 31;
        while(n > 0)
        {
            if(n%2 == 1)
                res += 1<<cnt;
            cnt--;
            n /= 2;
        }
        return res;
    }
};