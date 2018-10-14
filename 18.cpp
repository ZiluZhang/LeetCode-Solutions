// 4 sum
// 和3 sum一样，多一层循环
// 处理重复：固定的两个数，如果都不是列入考虑的第一个数，且和前面的一样，就跳过 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 4) return res;
        sort(nums.begin(), nums.end());
        int left = 0, right = len-1;
        for(int i = 0; i < len-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                left = j+1;
                right = len-1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};