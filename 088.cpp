// Merge Sorted Array
// 从后往前，in place
// 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        int i = m-1, j = n-1;
        int idx = m+n-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) nums1[idx--] = nums1[i--];
            else nums1[idx--] = nums2[j--];
        }
        while(j >= 0) {
            nums1[idx--] = nums2[j--];
        }
        return;
    }
};


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m-1, j = n-1;
//         int k = m+n-1;
//         while(i >=0 && j >= 0)
//         {
//             if(nums1[i] >= nums2[j])
//             {
//                 nums1[k] = nums1[i];
//                 i -= 1;
//                 k -= 1;
//             }
//             else
//             {
//                 nums1[k] = nums2[j];
//                 j -= 1;
//                 k -= 1;
//             }
//         }
//         while(i >= 0)
//         {
//             nums1[k] = nums1[i];
//             i -= 1;
//             k -= 1;
//         }
//         while(j >= 0)
//         {
//             nums1[k] = nums2[j];
//             j -= 1;
//             k -= 1;
//         }
//         return;
//     }
// };