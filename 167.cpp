// Two Sum II - Input array is sorted
// 左右指针，找


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right) {
            int cur = numbers[left] + numbers[right];
            if(cur == target) return {left+1, right+1};
            else if(cur < target) left++;
            else right--;
        }
        return {};
    }
};