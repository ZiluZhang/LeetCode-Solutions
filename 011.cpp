// Container With Most Water
// container问题，两个指针分别从两边往中间挪
// 哪边的小，下一步就挪哪边的指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len < 2) return 0;
        if(len == 2)
            return min(height[0], height[1]);
        int i = 0, j = len - 1;
        int res = 0;
        int tmp = 0;
        while(i < j) {
            tmp = (min(height[i], height[j]) * (j - i));
            res = max(tmp, res);
            height[i] < height[j] ? ++i: --j;
        }
        return res;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int len = height.size();
//         int l = 0;
//         int r = len-1;
//         int res = 0;
//         while(l < r)
//         {
//             res = max(res, min(height[l], height[r]) * (r - l));
//             if(height[l] < height[r])
//                 l++;
//             else
//                 r--;
//         }
//         return res;
//     }
// };