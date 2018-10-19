// Remove Duplicates from Sorted Array
// ++i先处理+再取值
// while循环里一定要记得index++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        int left = 0;
        int right = 1;
        while(right < len) {
            if(nums[right] != nums[left])
                nums[++left] = nums[right];
            right++;
        }
        return left+1;
    }
};


// // class Solution {
// // public:
// //     int removeDuplicates(vector<int>& nums) {
// //         int len = nums.size();
// //         if(len == 0) return 0;
// //         int i = 0, j = 0;
// //         while(i < len && j < len)
// //         {
// //             while(j < len && nums[i] == nums[j])
// //                 j++;
// //             // cout << i << ' ' << j << ' ' << nums[i] << ' ' << nums[j] << endl;
// //             if(j >= len)
// //                 break;
// //             int tmp = nums[j];
// //             nums[j] = nums[i+1];
// //             nums[i+1] = tmp;
// //             i += 1;
// //             j += 1;
// //         }
// //         // cout << i << j << endl;
// //         // for(int k = 0; k < len; k++)
// //             // cout << nums[k] << endl;
// //         return i+1;
// //     }
// // };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int len = nums.size();
//         if(len <= 1)
//             return len;
//         int i = 0;
//         int j = 1;
//         while(j < len)
//         {
//             while(j < len && nums[j] == nums[i])
//                 j++;
//             if(j >= len)
//                 break;
//             nums[i+1] = nums[j];
//             i++;
//             j++;
//         }
//         return i+1;
//     }
// };