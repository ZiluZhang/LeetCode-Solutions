// Move Zoros
// 
// 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }
        for(int i = idx; i < len; i++)
            nums[i] = 0;
        return;
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int len = nums.size();
//         int i = 0, j = 0;
//         while(j < len)
//         {
//             while(nums[j] == 0)
//                 j++;
//             if(j >= len)
//                 break;
//             int tmp = nums[j];
//             nums[j] = nums[i];
//             nums[i] = tmp;
//             i++;
//             j++;
//         }
//         while(i < len)
//         {
//             nums[i] = 0;
//             i++;
//         }
//         return;
//     }
// };