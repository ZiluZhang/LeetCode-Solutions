// 取负数，用0-x
// 判断是否越界，可以先用long表示，如果(int)num!=num就说明越界
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x < 0) {
            neg = true;
            x = 0-x;
        }
        long res = 0;
        while(x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if((int)res != res)
            return 0;
        if(neg)
            return 0-res;
        return res;
    }
};


// class Solution {
// public:
//     int reverse(int x) {
//         vector<int> tmp;
//         cout << x << endl;
//         bool neg = false;
//         if(x < 0)
//         {
//             neg = true;
//             x = 0-x;
//         }
//         // while(x > 0)
//         // {
//         //     tmp.push_back(x%10);
//         //     cout << x%10 << endl;
//         //     x = x/10;
//         // }
//         // long int res = 0;
//         // for(int i = 0; i < tmp.size(); i++)
//         // {
//         //     res = res * 10 + tmp[i];
//         //     cout << res << endl;
//         // }
//         // if((int)res != res)
//         //     return 0;
//         // cout << res << endl;
//         // if(neg)
//         //     res = 0-res;
//         // cout << res << endl;
//         // cout << -res << endl;
//         // return res;
//         long int res = 0;
//         while(x > 0)
//         {
//             res = res * 10 + x % 10;
//             x /= 10;
//         }
//         if((int)res != res)
//             return 0;
//         if(neg)
//             return 0-res;
//         return res;
//     }
// };