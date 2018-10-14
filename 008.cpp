// INT_MAX和INT_MIN在limits.h里面有
// string转int可能在转化过程中就超，所以每一轮都查一遍
#include <limits.h>
class Solution {
public:
    int myAtoi(string str) {
        bool neg = false;
        int len = str.length();
        long long res = 0;
        int i = 0;
        while(i < len && str[i] == ' ')
            i++;
        // cout << i << " " << len << endl;
        if(i >= len)
            return 0;
        if(str[i] == '-') {
            neg = true;
            i++;
        }
        else if(str[i] == '+') {
            neg = false;
            i++;
        }
        if(str[i] > '9' || str[i] < '0')
            return 0;
        int begin = i;
        while(i < len && '0' <= str[i] && str[i] <= '9') {
            // cout << (str[i]-'0') << " ";
            res = res * 10 + (str[i]-'0');
            if((int)res != res) {
                if(neg)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            i++;
        }
        if(neg)
            res = 0-res;
        // if((int)res != res) {
        //     if(neg)
        //         return INT_MIN;
        //     else
        //         return INT_MAX;
        // }
        return res;
    }
};