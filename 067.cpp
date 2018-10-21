// Add Binary
// 这题要仔细，要倒着存！
// 
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        if(lena == 0) return b;
        if(lenb == 0) return a;
        vector<int> numa;
        vector<int> numb;
        for(int i = lena-1; i >= 0; i--)
            numa.push_back(a[i]-'0');
        for(int i = lenb-1; i >= 0; i--)
            numb.push_back(b[i]-'0');
        vector<int> res;
        int i = 0;
        int s = 0;
        while(i < lena && i < lenb) {
            res.push_back((numa[i] + numb[i] + s) % 2);
            s = (numa[i] + numb[i] + s) / 2;
            i++;
        }
        while(i < lena) {
            res.push_back((numa[i] + s) % 2);
            s = (numa[i] + s) / 2;
            i++;
        }
        while(i < lenb) {
            res.push_back((numb[i] + s) % 2);
            s = (numb[i] + s) / 2;
            i++;
        }
        if(s > 0) {
            res.push_back(s);
        }
        int len = res.size();
        string rt = "";
        for(i = len-1; i >= 0; i--) {
            rt += res[i] + '0';
        }
        return rt;
    }
};

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int len1 = a.length();
//         int len2 = b.length();
//         vector<int> num1, num2;
//         for(int i = len1-1; i >= 0; i--)
//         {
//             if(a[i] == '1')
//                 num1.push_back(1);
//             else
//                 num1.push_back(0);
//         }
//         for(int j = len2-1; j >= 0; j--)
//         {
//             if(b[j] == '1')
//                 num2.push_back(1);
//             else
//                 num2.push_back(0);
//         }
//         vector<int> sum;
//         int c = 0;
//         for(int i = len1; i < len2; i++)
//             num1.push_back(0);
//         for(int i = len2; i < len1; i++)
//             num2.push_back(0);
//         for(int i = 0; i < len1 || i < len2; i++)
//         {
//             int tmp = num1[i] + num2[i] + c;
//             sum.push_back(tmp%2);
//             c = tmp / 2;
//         }
//         if(c == 1)
//             sum.push_back(c);
//         int len3 = sum.size();
//         string res = "";
//         for(int i = 0; i < len3; i++)
//         {
//             if(sum[i] == 0)
//                 res = "0" + res;
//             else
//                 res = "1" + res;
//         }
//         return res;
//     }
// };