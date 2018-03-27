class Solution {
public:
    bool isPerfectSquare(int num) {
        long int left = 1;
        long int right = num;
        while(left < right)
        {
            long int mid = left + (right - left) / 2;
            if(mid * mid == num)
            {
                cout << mid << endl;
                return true;
            }
            else if(mid * mid < num)
                left = mid + 1;
            else if(mid * mid > num)
                right = mid;
        }
        cout << left << endl;
        if(left * left == num)
            return true;
        else
            return false;
    }
};