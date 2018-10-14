// 3 sum
// unique!!!!!
// 先排序
// 固定一个负数或0，找另外两个数
// 另外两个数查找范围是右边所有，用头尾两个指针找，小了就挪头指针，大了就挪尾指针
// 因为要unique，找到了之后，要跳过所有重复的数（两个数要跳，负数或0也要跳）
// while循环里一定记得idx++
// 往二维vector里加一行，这一行用{}表示
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 3)
            return res;
        sort(nums.begin(), nums.end());
        int neg_idx = 0;
        int left = 0, right = len-1;
        while(neg_idx < len && nums[neg_idx] <= 0) {
            if(neg_idx > 0 && nums[neg_idx] == nums[neg_idx-1]) {
                neg_idx++;
                continue;
            }
            left = neg_idx+1;
            right = len-1;
            while(left < right) {
                if(nums[left] + nums[right] + nums[neg_idx] == 0) {
                    res.push_back({nums[neg_idx], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1])
                        left++;
                    while(left < right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] + nums[neg_idx] < 0)
                    left++;
                else
                    right--;
            }
            neg_idx++;
        }
        return res;
    }
};