class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        map<int, int> cnt;
        vector<int> intersect;
        for(int i = 0 ; i < len1; i++)
        {
            if(cnt.find(nums1[i]) == cnt.end())
                cnt.insert(pair<int, int>(nums1[i], 1));
        }
        for(int i = 0 ; i < len2; i++)
        {
            if(cnt.find(nums2[i]) != cnt.end() && cnt[nums2[i]] == 1)
            {
                cnt[nums2[i]]++;
                intersect.push_back(nums2[i]);
            }
        }
        return intersect;
    }
};