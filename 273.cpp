// Integer to English Words
// 每三位一算
// 


class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = convert3(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for(int i = 0; i < 3; i++) {
            num /= 1000;
            if(num == 0) break;
            res = num % 1000 ? convert3(num % 1000) + " " + v[i] + (res.empty() ? "" : " ") + res : res;
        }
        return res;
    }
    
    string convert3(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b/10] + (c ? " " + v1[c] : "");
        if(a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};