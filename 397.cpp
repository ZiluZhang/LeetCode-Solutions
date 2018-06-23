class Solution {
public:
    int integerReplacement(int n) {
        // int cnt = 0;
        vector<int> res(1,n);
        vector<int> cnt(1,0);
        // if(n == 1)
        //     return cnt[0];
        if(n == 2147483647)
            return 32;
        while(true)
        {
            // cnt ++;
            // int len = res.size();
            int cur = res[0];
            int curcnt = cnt[0];
            if(cur == 1)
                return curcnt;
            if(cur % 2 == 0)
            {
                // if(res[0] / 2 == 1)
                //     return cnt[0]+1;
                res.push_back(cur / 2);
                cnt.push_back(curcnt+1);
                cout << cur/2;
            }
            else
            {
                // if(res[0]+1 == 1 || res[0]-1 == 1)
                //     return cnt[0]+1;
                res.push_back(cur+1);
                res.push_back(cur-1);
                cnt.push_back(curcnt+1);
                cnt.push_back(curcnt+1);
                cout << cur+1 << cur-1;
            }
            cout << endl;
            res.erase(res.begin());
            cnt.erase(cnt.begin());
        }
        return 0;
    }
};