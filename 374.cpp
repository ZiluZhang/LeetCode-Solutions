// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        // cout << guess(n) << endl;
        int left = 1;
        int right = n;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) < 0)
            {
                right = mid;
            }
            else if(guess(mid) > 0)
            {
                left = mid + 1;
            }
        }
        return left;
    }
};