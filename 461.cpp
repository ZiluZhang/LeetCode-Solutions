class Solution {
public:
    int hammingDistance(int x, int y) {
        int dif = 0;
        while(x > 0 && y > 0)
        {
            if(x % 2 != y % 2)
                dif++;
            x /= 2;
            y /= 2;
        }
        while(x > 0)
        {
            dif += x % 2;
            x /= 2;
        }
        while(y > 0)
        {
            dif += y % 2;
            y /= 2;
        }
        return dif;
    }
};