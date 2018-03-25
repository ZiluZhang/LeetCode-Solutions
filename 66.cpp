class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // digits[0] = digits[0] + 1;
        // if(digits[0] == 10)
        // {
        //     digits[0] = 1;
        //     digits.push_back(0);
        // }
        int len = digits.size();
        // for(int i = 0; i < len; i++)
        //     digits[i] += 1;
        digits[len-1] += 1;
        int addone = 0;
        for(int j = len-1; j >= 0; j--)
        {
            int thisdigit = digits[j] + addone;
            addone = thisdigit / 10;
            digits[j] = thisdigit % 10;
        }
        if(addone > 0)
            digits.insert(digits.begin(), addone);
        return digits;
    }
};