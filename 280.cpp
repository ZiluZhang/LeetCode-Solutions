// Wiggle Sort
// nums[0] <= nums[1] >= nums[2] <= nums[3]....
// in-place 遍历一遍判断奇偶 要不要swap 就行了

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int num = nums.size();
        for(int i = 1; i < num; i++) {
            if((i % 2 == 0 && nums[i-1] < nums[i]) || (i % 2 == 1 && nums[i-1] > nums[i]) ) {
                swap(nums[i], nums[i-1]);
            }
        }
        return;
    }
};