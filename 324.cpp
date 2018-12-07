// Wiggle Sort II


// 先排序，然后分两半
// 按奇偶，从某一半拿
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int num = nums.size();
        int k = (num + 1) / 2;
        int j = num;
        for(int i = 0; i < num; i++) {
            if(i % 2 == 0)
                nums[i] = tmp[--k];
            else
                nums[i] = tmp[--j];
        }
        return;
    }
};