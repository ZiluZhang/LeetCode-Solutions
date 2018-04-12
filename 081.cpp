class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[l] < nums[mid])
            {
                if(nums[l] <= target && target <= nums[mid])
                    r =  mid;
                else
                    l = mid + 1;
            }
            else if(nums[mid] < nums[r])
            {
                if(nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                if(nums[l] == nums[mid])
                    l++;
                if(nums[r] == nums[mid])
                    r--;
            }
        }
        return false;
    }
};