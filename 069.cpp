// Sqrt(x)
// 二分法查，最后return right
// 防止越界，不要用乘法


class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 1, right = x-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(x / mid == mid) return mid;
            else if(x / mid > mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x <= 1)
//             return x;
//         int l = 0, r = x;
//         while(l <= r)
//         {
//             int m = l + (r-l)/2;
//             if(m == x/m)
//                 return m;
//             else if(m < x/m)
//                 l = m+1;
//             else if(m > x/m)
//                 r = m-1;
//         }
//         return r;
//     }
// };