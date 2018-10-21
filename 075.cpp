// Sort Colors
// 两个指针，记录0和2下一个该存哪，循环的时候i<idx2+1
// for循环不写i++，如果是0/1需要i++，2不需要，因为swap过来的数还没有排序

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int idx0 = 0, idx2 = len-1;
        int tmp = 0;
        for(int i = 0; i < idx2 + 1;) {
            if(nums[i] == 0) {
                nums[i] = nums[idx0];
                nums[idx0] = 0;
                idx0++;
                i++;
            }
            else if(nums[i] == 2) {
                nums[i] = nums[idx2];
                nums[idx2] = 2;
                idx2--;
            }
            else i++;
        }
        return;
    }
};