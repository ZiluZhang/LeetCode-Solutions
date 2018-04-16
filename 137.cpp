class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digs(32,0);
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int cur = nums[i];
            for(int k = 0; k < 32; k++)
            {
                digs[k] += cur & 1;
                cur >>= 1;
                if(!cur)
                    break;
            }
        }
        int res = 0;
        for(int k = 0; k < 32; k++)
        {
            if((digs[k] % 3))
                res += 1 << k;
        }
        return res;
    }
};