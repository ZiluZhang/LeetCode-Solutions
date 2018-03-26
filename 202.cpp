class Solution {
public:
    bool isHappy(int n) {
        map<int, int> cnt;
        while(n != 1)
        {
            if(cnt.find(n) == cnt.end())
                cnt.insert(pair<int, int>(n, 1));
            else
                return false;
            int tmp = n;
            int dig = 0;
            vector<int> digits;
            while(tmp != 0)
            {
                digits.push_back(tmp%10);
                tmp /= 10;
                dig++;
            }
            // cout << n << " " << dig << endl;
            n = 0;
            int len = digits.size();
            for(int i = 0; i < len; i++)
                n += digits[i] * digits[i];
        }
        return true;
    }
};