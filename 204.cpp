class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int endnum = (int)sqrt(n);
        cout << endnum << endl;
        for(int i = 2; i <= endnum; i++)
        {
            if(!isPrime[i-1])
                continue;
            int s = i * i;
            for(int j = s; j <= n; j+=i)
                isPrime[j-1] = false;
        }
        int cnt = 0;
        for(int i = 1; i < n-1; i++)
            if(isPrime[i])
                cnt++;
        return cnt;
    }
};