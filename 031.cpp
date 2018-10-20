// Next Permutation
// 从右向左遍历，找到一个连续不减序列，它左边那个数比这个序列所有数都小
// 在序列中找到第一个比它大的（因为连续不减，所以从右向左遍历找就行）
// 这俩数交换
// 对这个连续不减序列sort
// 边界：如果连续不减序列就是完整序列，说明已经是最大permutation，sort一下就行

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int firstdecend = len-1;
        while(firstdecend >= 1 && nums[firstdecend] <= nums[firstdecend-1])
            firstdecend--;
        firstdecend--;
        if(firstdecend < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int firstbigger = len-1;
        while(firstbigger >= 1 && nums[firstbigger] <= nums[firstdecend])
            firstbigger--;
        int tmp = nums[firstdecend];
        nums[firstdecend] = nums[firstbigger];
        nums[firstbigger] = tmp;
        sort(nums.begin()+firstdecend+1, nums.end());
        return;
    }
};

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int len = nums.size();
//         vector<int> tmp(nums);
//         sort(tmp.rbegin(), tmp.rend());
//         if(tmp == nums)
//         {
//             sort(nums.begin(), nums.end());
//             return;
//         }
//         int i = len-1;
//         while(i > 0 && nums[i] <= nums[i-1])
//             i--;
//         int k = i-1;
//         int t = nums[i];
//         if(k >= 0)
//         {
//             for(int j = i+1; j < len; j++)
//             {
//                 if(nums[j] > nums[k] && t > nums[j])
//                 {
//                     t = nums[j];
//                     i=j;
//                     cout << i << j << endl;
//                 }
//             }
//             cout << i << k << endl;
//             swap(nums[k], nums[i]);
//             sort(nums.begin()+k+1, nums.end());
//         }
//         return;
//     }
    
//     void swap(int& a, int& b)
//     {
//         int tmp = a;
//         a = b;
//         b = tmp;
//         return;
//     }
// };

// //     void nextPermutation(vector<int>& nums) {
// //         vector<int> a(nums);
// //         sort(a.rbegin(), a.rend());
// //         if(a==nums){
// //             sort(nums.begin(),nums.end());
// //         }
// //         else{
// //         int i = nums.size() - 1;
// //         while(i>0&&nums[i]<=nums[i-1]){
// //             i--;
// //         }
// //         int k=i-1,t=nums[i];
// //         if(k>=0){
// //             for(int j=i+1;j<nums.size();j++){
// //                 if(nums[j]>nums[k]&&t>nums[j]){
// //                     t=nums[j];
// //                     i=j;
// //                 }
// //             }
// //             swap(nums[k],nums[i]);
// //             sort(nums.begin() + k+1,nums.end());
// //             }
// //         }

// //     }