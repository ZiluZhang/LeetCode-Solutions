class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        vector<int> num1, num2;
        for(int i = len1-1; i >= 0; i--)
        {
            if(a[i] == '1')
                num1.push_back(1);
            else
                num1.push_back(0);
        }
        for(int j = len2-1; j >= 0; j--)
        {
            if(b[j] == '1')
                num2.push_back(1);
            else
                num2.push_back(0);
        }
        vector<int> sum;
        int c = 0;
        for(int i = len1; i < len2; i++)
            num1.push_back(0);
        for(int i = len2; i < len1; i++)
            num2.push_back(0);
        for(int i = 0; i < len1 || i < len2; i++)
        {
            int tmp = num1[i] + num2[i] + c;
            sum.push_back(tmp%2);
            c = tmp / 2;
        }
        if(c == 1)
            sum.push_back(c);
        int len3 = sum.size();
        string res = "";
        for(int i = 0; i < len3; i++)
        {
            if(sum[i] == 0)
                res = "0" + res;
            else
                res = "1" + res;
        }
        return res;
    }
};