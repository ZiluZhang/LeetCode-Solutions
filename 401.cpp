class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        gettime(num, 0, 0, res);
        return res;
    }
    
    void gettime(int num, int mask, int start, vector<string>& res)
    {
        if(num == 0)
        {
            int m = mask & ((1<<6)-1);
            int h = mask >> 6;
            if(h > 11 || m > 59)
                return;
            string tmp;
            // if(h < 10)
            //     tmp += '0';
            tmp += to_string(h);
            tmp += ':';
            if(m < 10)
                tmp += '0';
            tmp += to_string(m);
            res.push_back(tmp);
            return;
        }
        
        for(int i = start; i < 10; i++)
        {
            gettime(num-1, mask | (1<<i), i+1, res);
        }
        return;
    }
};

// public List<String> readBinaryWatch(int num) {
//         List<String> res = new ArrayList<>();
//         solve(num, 0,0, res);
//         return res;
//     }
    
//     void solve(int num, int mask,int start, List<String> res) {
//         if (num == 0) {
//             int min = mask & ((1 << 6) - 1);
//             int hour = mask >> 6;
//             if (hour > 11 || min > 59) return;
//             res.add(String.format("%d:%02d", hour, min));
//             return;
//         }
        
//         for (int i = start; i < 10; i++) {
//             solve(num - 1, mask | (1 << i),i + 1, res);
//         }
//     }