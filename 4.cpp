class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n)%2 == 1)
            return findK(nums1, 0, nums2, 0, (m+n)/2+1);
        else
            return (findK(nums1, 0, nums2, 0, (m+n)/2) + findK(nums1, 0, nums2, 0, (m+n)/2+1)) / 2.0;
    }
    double findK(vector<int>& n1, int k1, vector<int>& n2, int k2, int k) {
        int m = n1.size();
        int n = n2.size();
        if(m-k1 > n-k2)
            return findK(n2, k2, n1, k1, k);
        if(m-k1 == 0) return n2[k2+k-1];
        if(k == 1) return min(n1[k1], n2[k2]);
        
        int mid1 = min(k/2, m-k1);
        int mid2 = k-mid1;
        if(n1[k1+mid1-1] < n2[k2+mid2-1])
            return findK(n1, k1+mid1, n2, k2, k-mid1);
        else if(n1[k1+mid1-1] > n2[k2+mid2-1])
            return findK(n1, k1, n2, k2+mid2, k-mid2);
        else
            return n1[k1+mid1-1];
    }
};


// public double findMedianSortedArrays(final int[] A, final int[] B) {
//     int total = A.length + B.length;
//     if (total %2 == 1)
//         return findKth(A, 0, B, 0, total / 2 + 1);
//     else
//         return (findKth(A, 0, B, 0, total / 2)
//                 + findKth(A, 0, B, 0, total / 2 + 1)) / 2.0;
// }

// private static int findKth(final int[] A, int ai, final int[] B, int bi, int k) {
//     //always assume that A is shorter than B
//     if (A.length - ai > B.length - bi) {
//         return findKth(B, bi, A, ai, k);
//     }
//     if (A.length - ai == 0) return B[bi + k - 1];
//     if (k == 1) return Math.min(A[ai], B[bi]);

//     //divide k into two parts
//     int k1 = Math.min(k / 2, A.length - ai), k2 = k - k1;
//     if (A[ai + k1 - 1] < B[bi + k2 - 1])
//         return findKth(A, ai + k1, B, bi, k - k1);
//     else if (A[ai + k1 - 1] > B[bi + k2 - 1])
//         return findKth(A, ai, B, bi + k2, k - k2);
//     else
//         return A[ai + k1 - 1];
// }