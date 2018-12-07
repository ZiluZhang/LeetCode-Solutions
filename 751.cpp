// IP to CIDR
// 把IP弄成一个区间一个区间的
// 每一个区间，用开头的ip表示，后面/相同位数
// 即表示和这个ip具有这么多相同位数的所有，并且这些都比开头大！
// 所以说相同位数必须覆盖到最后一个1
// x&-x可以得到最后一个1的位置 因为-x == ~x+1

// string to_string(int)
// int atoi(string)

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        long num = ip2int(ip);
        vector<string> res;
        while(n > 0) {
            long step = num & (-num);
            while(step > n) step /= 2;
            res.push_back(int2ip(num, step));
            num += step;
            n -= step;
        }
        return res;
    }
    
    long ip2int(string ip) {
        long num = 0;
        int cur = 0;
        for(int i = 0; i <= ip.length(); i++) {
            if(ip[i] == '.' || i == ip.length()) {
                num = num * 256 + cur;
                cur = 0;
            }
            else {
                cur = cur * 10 + ip[i] - '0';
            }
        }
        return num;
    }
    
    string int2ip(long tmp, int step) {
        int mask = 256;
        string ans = "";
        ans += to_string(tmp % mask);
        for(int i = 0; i < 3; i++) {
            tmp /= mask;
            ans = "." + ans;
            ans = to_string(tmp % mask) + ans;
        }
        int k = 33;
        while(step > 0) {
            k--;
            step /= 2;
        }
        ans += "/" + to_string(k);
        return ans;
    }
};