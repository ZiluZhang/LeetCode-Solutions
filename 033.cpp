class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len-1;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }
        int idx = l;
        l = 0;
        r = len-1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            int cur = (mid + idx) % len;
            if(nums[cur] == target)
                return cur;
            else if(nums[cur] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};