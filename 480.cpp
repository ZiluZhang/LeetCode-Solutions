// Sliding Window Median
// 类似295，用两个multiset分别记录左半边和右半边

// 注意，end()这个iteration指向最后，是空的！--xxx.end()才指向xxx中最后一个元素
// *(it)取值
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> small, large;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                if(small.count(nums[i-k])) small.erase(small.find(nums[i-k]));
                else large.erase(large.find(nums[i-k]));
            }
            if(small.size() <= large.size()) { // put in small
                if(large.empty() || nums[i] <= *large.begin())
                    small.insert(nums[i]);
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            }
            else { // put in large
                if(nums[i] >= *small.rbegin())
                    large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if(i >= k-1) {
                if(k % 2) res.push_back(*small.rbegin());
                else
                    res.push_back((*small.rbegin() + *large.begin()) / 2.0);
            }
        }
        return res;
    }
};