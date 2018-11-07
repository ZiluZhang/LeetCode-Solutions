// Rotate Array
// 一轮一轮来，每轮中每个元素跨k个
// 通过记录每一轮start位置判断是否结束一轮

// 也可以先reverse前n-k个，再reverse后k个，再reverse整个


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0 || (k % len) == 0) return;
        int start = 0;
        int i = 0;
        int cur = nums[i];
        int cnt = 0;
        while(cnt++ < len) {
            i = (i + k) % len;
            int t = nums[i];
            nums[i] = cur;
            if(i == start) {
                start++;
                i++;
                cur = nums[start];
            } else {
                cur = t;
            }
        }
        return;
    }
};


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int len = nums.size();
//         while(k > 0)
//         {
//             int tmp = nums[len-1];
//             nums.pop_back();
//             nums.insert(nums.begin(), tmp);
//             k--;
//         }
//         return;
//     }
// };