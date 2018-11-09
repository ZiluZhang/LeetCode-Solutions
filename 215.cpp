// Kth Largest Element in an Array
// 快排！
// 

// priority_queue默认最大堆，但这个题应该用最小堆，所以存相反数
// 堆大小为k，后面的数，如果比堆顶大，就替换
// 返回堆顶
// O(nlogk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        priority_queue<int> q;
        for(int i = 0; i < k; i++)
            q.push(-nums[i]);
        for(int i = k; i < len; i++) {
            if(q.top() > -nums[i]) {
                q.pop();
                q.push(-nums[i]);
            }
        }
        return -q.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0, right = len-1;
        while(true) {
            int tmp = fastsort(nums, left, right);
            if(tmp == k-1) return nums[tmp];
            else if(tmp < k-1) left = tmp + 1;
            else right = tmp - 1;
        }
        return -1;
    }
    
    int fastsort(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while(l <= r) {
            if(nums[l] < pivot && pivot < nums[r]) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};