// Excel Sheet Column Title
// 循环内用n-1代表n的一切
// 

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0)
        {
            int tmp = n-1;
            cout << tmp << endl;
            cout << (char)('A'+tmp%26) << endl;
            res = (char)('A' + tmp % 26) + res;
            n = tmp / 26;
        }
        return res;
    }
};