// Multiply Strings
// 大整数乘法
// 记得从后向前
// 记得每一位相乘后要加进位、当前这一个位置的结果
// 记得每一轮结束后如果还有进位，要补上
// 记得最后要从后向前输出，并把前面的连续0去掉

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if(len1 == 0 || len2 == 0) return "0";
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> res(len1+len2+1, 0);
        vector<int> n1;
        vector<int> n2;
        for(int i = len1-1; i >= 0; i--)
            n1.push_back(num1[i]-'0');
        for(int j = len2-1; j >= 0; j--)
            n2.push_back(num2[j]-'0');
        int s = 0;
        for(int i = 0; i < len1; i++) {
            s = 0;
            for(int j = 0; j < len2; j++) {
                int cur = res[i+j] + n1[i] * n2[j] + s;
                res[i+j] = cur % 10;
                s = cur / 10;
            }
            if(s != 0)
                res[i+len2] = s;
        }
        string mul = "";
        int idx = len1 + len2;
        while(idx >= 0 && res[idx] == 0) idx--;
        for(int i = idx; i >= 0; i--)
            mul += res[i] + '0';
        return mul;
    }
};